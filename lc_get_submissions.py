"""
Pull your latest ACCEPTED LeetCode submission for each problem into lc\\.

Step 1: runs lc_get_titles (renames number-only files, creates blank files
        for every problem that has none).
Step 2: finds your latest accepted submission per problem and writes it into
        {number:04d}-{slug}.{ext}, using the extension of the language you
        submitted in (a blank .cpp placeholder is removed if the accepted
        submission was, say, Python).

Your own work is protected:
  * A problem whose file(s) already contain code is SKIPPED by default.
    Only blank placeholders get filled in.
  * --overwrite also replaces files that contain code, but only when the code
    actually differs (newline differences are ignored), and the old version is
    first copied to _lc_backup\\ next to the lc folder.
  * Non-empty files are never deleted. Only zero-byte placeholders are removed.

Login comes from a .env file next to this script (or real environment
variables), never from the code:
    LEETCODE_SESSION=...
    CSRF_TOKEN=...
(Browser dev tools -> Cookies -> leetcode.com -> LEETCODE_SESSION and csrftoken)

Usage:
  python lc_get_submissions.py               # fill blanks with accepted code
  python lc_get_submissions.py --dry-run     # show what would happen
  python lc_get_submissions.py --overwrite   # also replace differing code
"""

import argparse
import os
import re
import sys
import time
from datetime import datetime
from pathlib import Path

import lc_get_titles

LC_DIR = Path(r"C:\Iris\dsa\lc")
GQL_URL = lc_get_titles.GQL_URL

PAGE_SIZE = 20
MAX_CONSECUTIVE_FAILURES = 5

# LeetCode's "lang" values -> file extensions.
LANG_EXT_MAP = {
    "c": "c",
    "cpp": "cpp",
    "java": "java",
    "python": "py",
    "python3": "py",
    "pythondata": "py",
    "javascript": "js",
    "typescript": "ts",
    "golang": "go",
    "go": "go",
    "rust": "rs",
    "csharp": "cs",
    "ruby": "rb",
    "swift": "swift",
    "kotlin": "kt",
    "scala": "scala",
    "php": "php",
    "dart": "dart",
    "racket": "rkt",
    "erlang": "erl",
    "elixir": "ex",
    "bash": "sh",
    "mysql": "sql",
    "mssql": "sql",
    "oraclesql": "sql",
    "postgresql": "sql",
    "sql": "sql",
}

LIST_QUERY = """
query submissionList($offset: Int!, $limit: Int!) {
  submissionList(offset: $offset, limit: $limit) {
    hasNext
    submissions {
      id
      titleSlug
      statusDisplay
      lang
    }
  }
}
"""

DETAIL_QUERY = """
query submissionDetails($submissionId: Int!) {
  submissionDetails(submissionId: $submissionId) {
    code
    question {
      questionFrontendId
    }
  }
}
"""


# --------------------------------------------------------------------------
# Credentials (.env)
# --------------------------------------------------------------------------


def read_dotenv(path):
    values = {}
    if not path.exists():
        return values
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        line = line.strip()
        if not line or line.startswith("#") or "=" not in line:
            continue
        key, _, value = line.partition("=")
        value = value.strip()
        if len(value) >= 2 and value[0] == value[-1] and value[0] in "\"'":
            value = value[1:-1]
        values[key.strip()] = value
    return values


def get_credentials():
    env_path = Path(__file__).with_name(".env")
    dotenv = read_dotenv(env_path)

    session = os.environ.get("LEETCODE_SESSION") or dotenv.get("LEETCODE_SESSION")
    csrf = os.environ.get("CSRF_TOKEN") or dotenv.get("CSRF_TOKEN")

    if not session or not csrf:
        sys.exit(
            "Missing LeetCode login.\n"
            f"Create {env_path} with two lines:\n"
            "  LEETCODE_SESSION=<cookie value>\n"
            "  CSRF_TOKEN=<csrftoken cookie value>\n"
            "(Browser dev tools -> Application/Storage -> Cookies -> leetcode.com)"
        )
    return session, csrf


def warn_if_env_not_ignored():
    gi = Path(__file__).with_name(".gitignore")
    ignored = False
    if gi.exists():
        lines = [
            l.strip()
            for l in gi.read_text(encoding="utf-8", errors="replace").splitlines()
        ]
        ignored = any(l in (".env", "/.env", ".env*", "*.env") for l in lines)
    if not ignored:
        print(
            "WARNING: .env is not listed in .gitignore. Add a line '.env' "
            "before you ever commit, or your login cookie ends up on GitHub.\n"
        )


# --------------------------------------------------------------------------
# LeetCode API
# --------------------------------------------------------------------------


def gql(query, variables, cookies, csrf):
    return lc_get_titles.http_json(
        GQL_URL,
        {"query": query, "variables": variables},
        cookies=cookies,
        headers={"Origin": "https://leetcode.com", "x-csrftoken": csrf},
    )


def with_retries(fn, tries=4, base=1.5):
    last = None
    for attempt in range(tries):
        try:
            return fn()
        except Exception as e:
            last = e
            time.sleep(base * (2**attempt))
    raise last


def fetch_accepted(cookies, csrf):
    """
    {titleSlug: {"id", "lang"}} using the NEWEST accepted submission per
    problem (the list is newest-first, so the first sighting wins).
    """
    accepted = {}
    offset = 0

    while True:

        def one_page():
            resp = gql(
                LIST_QUERY, {"offset": offset, "limit": PAGE_SIZE}, cookies, csrf
            )
            block = (resp.get("data") or {}).get("submissionList")
            if not block:
                raise ValueError("no submissionList in response")
            return block

        try:
            block = with_retries(one_page)
        except Exception as e:
            if offset == 0:
                raise RuntimeError(
                    "Could not read your submission list. The cookie in .env is "
                    f"probably expired or wrong ({type(e).__name__}: {e})."
                )
            print(
                f"  Stopped paging at offset {offset} ({type(e).__name__}); "
                "continuing with what was read."
            )
            break

        for sub in block.get("submissions") or []:
            if sub.get("statusDisplay") != "Accepted":
                continue
            slug = sub.get("titleSlug")
            if slug and slug not in accepted:
                accepted[slug] = {"id": sub.get("id"), "lang": sub.get("lang")}

        offset += PAGE_SIZE
        print(
            f"  Read {offset} submissions... accepted problems so far: {len(accepted)}"
        )
        if not block.get("hasNext"):
            break
        time.sleep(0.3)

    return accepted


def fetch_code(submission_id, cookies, csrf):
    def one():
        resp = gql(DETAIL_QUERY, {"submissionId": int(submission_id)}, cookies, csrf)
        details = (resp.get("data") or {}).get("submissionDetails")
        if not details or not details.get("code"):
            raise ValueError("no code in response")
        return details["code"]

    return with_retries(one, tries=3, base=1.0)


# --------------------------------------------------------------------------
# Local files
# --------------------------------------------------------------------------


def build_index(lc):
    """{problem number: [files]} for names like 0001-two-sum.cpp / 0001.cpp."""
    index = {}
    for p in lc.iterdir():
        if p.is_file():
            m = re.fullmatch(r"(\d+)(?:-.+)?", p.stem)
            if m:
                index.setdefault(int(m.group(1)), []).append(p)
    return index


def is_blank(path):
    try:
        size = path.stat().st_size
        if size == 0:
            return True
        if size > 4096:
            return False
        return path.read_text(encoding="utf-8", errors="replace").strip() == ""
    except OSError:
        return False


def norm(text):
    return text.replace("\r\n", "\n").replace("\r", "\n")


# --------------------------------------------------------------------------
# Main
# --------------------------------------------------------------------------


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dir", default=str(LC_DIR), help="the lc folder")
    ap.add_argument(
        "--overwrite",
        action="store_true",
        help="also replace files that already contain different code (backed up)",
    )
    ap.add_argument(
        "--dry-run", action="store_true", help="change nothing, just report"
    )
    ap.add_argument(
        "--skip-paid", action="store_true", help="no blank files for premium problems"
    )
    args = ap.parse_args()

    lc = Path(args.dir)
    dry = args.dry_run

    warn_if_env_not_ignored()
    session, csrf = get_credentials()
    cookies = {"csrftoken": csrf, "LEETCODE_SESSION": session}

    print("=== Step 1/2: titles (rename + blank files) ===")
    problems = lc_get_titles.sync_titles(lc, apply=not dry, skip_paid=args.skip_paid)
    slug_to_number = {slug: number for number, (slug, _paid) in problems.items()}

    print("\n=== Step 2/2: latest accepted submissions ===")
    try:
        accepted = fetch_accepted(cookies, csrf)
    except RuntimeError as e:
        sys.exit(str(e))
    print(f"Accepted problems on LeetCode: {len(accepted)}")

    index = build_index(lc)
    backup_dir = lc.parent / "_lc_backup"

    todo, skipped_local, unknown = [], 0, []
    for slug, info in accepted.items():
        number = slug_to_number.get(slug)
        if number is None:
            unknown.append(slug)
            continue
        files = index.get(number, [])
        has_code = any(not is_blank(f) for f in files)
        if has_code and not args.overwrite:
            skipped_local += 1
            continue
        todo.append((number, slug, info))
    todo.sort()

    print(f"  Already have your code (left alone): {skipped_local}")
    print(f"  To fetch:                            {len(todo)}")
    if unknown:
        print(f"  Not in problem list (skipped):       {len(unknown)}")

    written = unchanged = replaced = removed = failed = 0
    consecutive_failures = 0

    for number, slug, info in todo:
        lang = (info.get("lang") or "").lower()
        ext = LANG_EXT_MAP.get(lang, "txt")
        target = lc / f"{number:04d}-{slug}.{ext}"
        files = index.get(number, [])

        try:
            code = fetch_code(info["id"], cookies, csrf)
            consecutive_failures = 0
        except Exception as e:
            failed += 1
            consecutive_failures += 1
            print(f"  FAILED {target.name}: {type(e).__name__}: {e}")
            if consecutive_failures >= MAX_CONSECUTIVE_FAILURES:
                print(
                    f"\n{MAX_CONSECUTIVE_FAILURES} failures in a row. Stopping so "
                    "LeetCode isn't hammered. Check your cookie and try again later."
                )
                break
            time.sleep(0.5)
            continue

        code = norm(code)
        existing = None
        if target.exists():
            existing = target.read_text(encoding="utf-8", errors="replace")

        if existing is not None and not is_blank(target):
            if norm(existing).rstrip() == code.rstrip():
                unchanged += 1
                print(f"  unchanged: {target.name}")
                time.sleep(0.3)
                continue
            # differs: only reachable with --overwrite
            if not dry:
                backup_dir.mkdir(exist_ok=True)
                stamp = datetime.now().strftime("%Y%m%d-%H%M%S")
                (backup_dir / f"{target.name}.{stamp}.bak").write_text(
                    existing, encoding="utf-8", newline=""
                )
            replaced += 1
            print(f"  replace:   {target.name} ({lang}), old copy backed up")
        else:
            written += 1
            print(f"  write:     {target.name} ({lang})")

        if not dry:
            target.write_text(code, encoding="utf-8")
            # Remove zero-byte placeholders for this problem (never real code).
            for f in files:
                if f != target and f.exists() and is_blank(f):
                    f.unlink()
                    removed += 1
        time.sleep(0.3)

    verb = "Would" if dry else "Did"
    print(f"\nDone ({'dry run' if dry else 'applied'}).")
    print(f"  {verb} write new:        {written}")
    print(f"  {verb} replace (backup): {replaced}")
    print(f"  Unchanged:               {unchanged}")
    print(f"  Placeholders removed:    {removed}")
    print(f"  Failed:                  {failed}")


if __name__ == "__main__":
    main()
