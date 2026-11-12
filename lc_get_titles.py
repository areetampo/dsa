"""
Tidy up the LeetCode folder (also used by lc_get_submissions.py).

1. Renames number-only files (0001.cpp, 1.cpp, ...) to {number:04d}-{slug}.ext
2. Creates an empty {number:04d}-{slug}.cpp for every LeetCode problem that has
   no file yet (any extension counts as "has a file").

The problem list comes from LeetCode's PUBLIC problem list (one request, no
login, NO cookies needed). The number is the frontend number shown on the site.

Safe by default:
  * Dry run unless you pass --apply
  * Never overwrites or deletes anything
  * Safe to re-run (nothing happens the second time)
  * Renames are written to lc_rename_log.txt next to this script

Usage:
  python lc_get_titles.py                 # dry run, shows what would happen
  python lc_get_titles.py --apply         # do it
  python lc_get_titles.py --apply --skip-paid     # no blanks for premium problems
  python lc_get_titles.py --problems-file list.json   # use a saved list (offline)
"""

import argparse
import json
import re
import sys
import time
import urllib.request
from pathlib import Path

LC_DIR = Path(r"C:\Iris\dsa\lc")

REST_URL = "https://leetcode.com/api/problems/all/"
GQL_URL = "https://leetcode.com/graphql"

HEADERS = {
    "User-Agent": (
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
        "(KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
    ),
    "Referer": "https://leetcode.com/",
    "Content-Type": "application/json",
}

GQL_QUERY = """
query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int,
                             $filters: QuestionListFilterInput) {
  problemsetQuestionList: questionList(
      categorySlug: $categorySlug, limit: $limit, skip: $skip, filters: $filters) {
    total: totalNum
    questions: data {
      frontendQuestionId: questionFrontendId
      title
      titleSlug
      paidOnly: isPaidOnly
    }
  }
}
"""

try:
    from curl_cffi import requests as cffi_requests
except ImportError:
    cffi_requests = None


# --------------------------------------------------------------------------
# HTTP (shared with lc_get_submissions.py)
# --------------------------------------------------------------------------


def http_json(url, payload=None, cookies=None, headers=None):
    """GET (no payload) or POST (payload) and return parsed JSON."""
    hdrs = dict(HEADERS)
    if headers:
        hdrs.update(headers)

    if cffi_requests is not None:
        kw = {"headers": hdrs, "impersonate": "chrome", "timeout": 60}
        if cookies:
            kw["cookies"] = cookies
        if payload is None:
            r = cffi_requests.get(url, **kw)
        else:
            r = cffi_requests.post(url, json=payload, **kw)
        r.raise_for_status()
        return r.json()

    if cookies:
        hdrs["Cookie"] = "; ".join(f"{k}={v}" for k, v in cookies.items())
    body = None if payload is None else json.dumps(payload).encode("utf-8")
    req = urllib.request.Request(url, data=body, headers=hdrs)
    with urllib.request.urlopen(req, timeout=60) as resp:
        return json.load(resp)


# --------------------------------------------------------------------------
# Getting the problem list
# --------------------------------------------------------------------------


def fetch_rest():
    return http_json(REST_URL)


def fetch_graphql():
    questions = []
    skip, limit = 0, 100
    while True:
        resp = http_json(
            GQL_URL,
            {
                "query": GQL_QUERY,
                "variables": {
                    "categorySlug": "",
                    "skip": skip,
                    "limit": limit,
                    "filters": {},
                },
            },
        )
        block = resp["data"]["problemsetQuestionList"]
        batch = block["questions"] or []
        questions.extend(batch)
        skip += limit
        if not batch or skip >= block["total"]:
            break
        time.sleep(0.5)
    return questions


def fetch_problems():
    try:
        data = fetch_rest()
        if normalize(data):
            print("Fetched problem list from LeetCode (REST).")
            return data
        print("REST list was empty, trying GraphQL...")
    except Exception as e:
        print(f"REST fetch failed ({type(e).__name__}: {e}), trying GraphQL...")

    data = fetch_graphql()
    print("Fetched problem list from LeetCode (GraphQL).")
    return data


def normalize(data):
    """Return {frontend_number: (slug, paid_only)} from any supported shape."""
    items = []

    if isinstance(data, dict) and "stat_status_pairs" in data:
        for pair in data["stat_status_pairs"]:
            stat = pair.get("stat", {})
            items.append(
                (
                    stat.get("frontend_question_id"),
                    stat.get("question__title_slug"),
                    bool(pair.get("paid_only")),
                )
            )
    else:
        if isinstance(data, dict):
            data = data.get("data", data)
        if isinstance(data, dict):
            data = data.get("problemsetQuestionList", data)
        if isinstance(data, dict):
            data = data.get("questions", [])
        for q in data or []:
            items.append(
                (
                    q.get("frontendQuestionId", q.get("frontend_id", q.get("id"))),
                    q.get("titleSlug", q.get("slug")),
                    bool(
                        q.get(
                            "paidOnly", q.get("isPaidOnly", q.get("paid_only", False))
                        )
                    ),
                )
            )

    out = {}
    for fid, slug, paid in items:
        try:
            number = int(str(fid).strip())
        except (TypeError, ValueError):
            print(f"  (skipping non-numeric problem id {fid!r})")
            continue
        if not slug:
            continue
        out.setdefault(number, (slug, paid))
    return out


# --------------------------------------------------------------------------
# The actual work
# --------------------------------------------------------------------------


def sync_titles(lc, apply, skip_paid=False, problems=None, raw=None, log_path=None):
    """
    Rename number-only files and create blank files for missing problems.
    Returns {frontend_number: (slug, paid_only)}.
    """
    lc = Path(lc)
    if not lc.is_dir():
        sys.exit(f"Folder not found: {lc}")

    if problems is None:
        if raw is None:
            raw = fetch_problems()
        problems = normalize(raw)
    if not problems:
        sys.exit("Could not read any problems from the list.")
    print(f"Problems in list: {len(problems)}")

    files = sorted(p for p in lc.iterdir() if p.is_file())

    # ---- Step 1: number-only files -> number-slug ------------------------
    renames, unknown, conflicts = [], [], []
    planned = set()

    for p in files:
        if not re.fullmatch(r"\d+", p.stem):
            continue
        number = int(p.stem)
        if number not in problems:
            unknown.append(p.name)
            continue

        slug = problems[number][0]
        new = p.with_name(f"{number:04d}-{slug}{p.suffix}")

        if new.exists() or new.name.lower() in planned:
            conflicts.append((p.name, new.name))
            continue

        planned.add(new.name.lower())
        renames.append((p, new))

    # ---- Step 2: which problems already have a file ----------------------
    present_ids, present_slugs = set(), set()
    for p in files:
        m = re.fullmatch(r"(\d+)(?:-(.+))?", p.stem)
        if m:
            present_ids.add(int(m.group(1)))
            if m.group(2):
                present_slugs.add(m.group(2).lower())
        else:
            present_slugs.add(p.stem.lower())

    to_create = []
    already_have = 0
    for number in sorted(problems):
        slug, paid = problems[number]
        if number in present_ids or slug.lower() in present_slugs:
            already_have += 1
            continue
        if skip_paid and paid:
            continue
        to_create.append(lc / f"{number:04d}-{slug}.cpp")

    # ---- Report -----------------------------------------------------------
    mode = "APPLYING" if apply else "DRY RUN (nothing changed)"
    print(f"\n{mode}")
    print(f"  Files to rename:            {len(renames)}")
    print(f"  Rename conflicts (skipped): {len(conflicts)}")
    print(f"  Unknown numbers (skipped):  {len(unknown)}")
    print(f"  Problems already have file: {already_have}")
    print(f"  Blank files to create:      {len(to_create)}")

    for old, new in renames[:8]:
        print(f"    {old.name}  ->  {new.name}")
    if len(renames) > 8:
        print(f"    ... and {len(renames) - 8} more")
    for a, b in conflicts[:30]:
        print(f"  ! conflict: {a} -> {b} already exists, left alone")
    for name in unknown[:30]:
        print(f"  ! not found in LeetCode list: {name}, left alone")

    if not apply:
        return problems

    # ---- Apply ------------------------------------------------------------
    log_path = (
        Path(log_path) if log_path else Path(__file__).with_name("lc_rename_log.txt")
    )
    with log_path.open("a", encoding="utf-8") as log:
        for old, new in renames:
            old.rename(new)
            log.write(f"{old.name}\t->\t{new.name}\n")

    created = 0
    for path in to_create:
        try:
            with path.open("x", encoding="utf-8"):
                pass
            created += 1
        except FileExistsError:
            pass

    print(f"\nRenamed {len(renames)} files (log: {log_path})")
    print(f"Created {created} blank files")
    return problems


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dir", default=str(LC_DIR), help="the lc folder")
    ap.add_argument("--problems-file", help="saved problem list JSON (skips download)")
    ap.add_argument("--apply", action="store_true", help="actually make changes")
    ap.add_argument(
        "--skip-paid",
        action="store_true",
        help="do not create blank files for premium-only problems",
    )
    args = ap.parse_args()

    raw = None
    if args.problems_file:
        raw = json.loads(Path(args.problems_file).read_text(encoding="utf-8"))

    sync_titles(Path(args.dir), apply=args.apply, skip_paid=args.skip_paid, raw=raw)

    if not args.apply:
        print("\nRun again with --apply to make these changes.")


if __name__ == "__main__":
    main()
