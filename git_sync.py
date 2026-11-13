"""
Sync this folder to GitHub: commit new/changed files and push.
Meant to run every ~30 minutes from Task Scheduler (git_setup.py sets that up).

What it does on each run:
  * Looks for new, changed or deleted files (git decides what counts as changed,
    so re-solving a problem with different code shows up, identical code doesn't).
  * Skips blank placeholder files (the empty .cpp files), so the thousands of
    empty LeetCode stubs never reach GitHub until you actually fill them in.
  * Skips a tracked file that has just become blank (probably a mistake; the
    old version stays in GitHub).
  * Skips files modified in the last 60 seconds (still being written/saved).
  * Respects .gitignore: if you add a folder that is already on GitHub (say
    "tests") to .gitignore, it stops tracking those files automatically. They
    stay on your PC and in git history, they just leave the current repo.
  * If git refuses one file, that file is reported in the log and everything
    else still goes through.
  * Scans every file it is about to upload for secrets (cookies, tokens, API
    keys, private keys). A file that looks like it has one is NOT uploaded.
  * Commits, then pushes. If you are offline the commit stays local and the
    next run pushes it. Never force-pushes.
  * Writes a short log to git_sync.log (kept small).

Usage:
  py git_sync.py              # normal run
  py git_sync.py --dry-run    # show what would be committed, change nothing
  py git_sync.py --no-push    # commit but do not push
  py git_sync.py --settle 0   # also include files saved in the last minute

Exit code: 0 ok, 1 commit/push problem, 2 a file was blocked by the secret scan.
"""

import argparse
import os
import re
import subprocess
import sys
import time
from datetime import datetime
from pathlib import Path

REPO = Path(__file__).resolve().parent

SETTLE_SECONDS = 60
LOCK_STALE_SECONDS = 15 * 60
MAX_FILE_BYTES = 5 * 1024 * 1024
GIT_TIMEOUT = 120
PUSH_TIMEOUT = 180
LOG_MAX_BYTES = 500_000
NO_WINDOW = 0x08000000 if os.name == "nt" else 0  # no console flash on Windows
OWN_FILES = {"git_sync.log", ".git_sync.lock"}

SECRET_PATTERNS = [
    (
        "JWT / session token",
        re.compile(r"eyJ[A-Za-z0-9_-]{15,}\.eyJ[A-Za-z0-9_-]{15,}\.[A-Za-z0-9_-]{10,}"),
    ),
    (
        "LeetCode/CSRF cookie value",
        re.compile(
            r"(?i)\b(LEETCODE_SESSION|CSRF_?TOKEN|csrftoken)\b\s*[=:]\s*['\"]?[A-Za-z0-9._\-]{20,}"
        ),
    ),
    (
        "API key / secret / password assignment",
        re.compile(
            r"(?i)\b(api[_-]?key|api[_-]?secret|secret|password|passwd|token)\b\s*[=:]\s*['\"][A-Za-z0-9/+_\-]{16,}['\"]"
        ),
    ),
    (
        "GitHub token",
        re.compile(
            r"\b(ghp_[A-Za-z0-9]{30,}|gho_[A-Za-z0-9]{30,}|github_pat_[A-Za-z0-9_]{30,})"
        ),
    ),
    ("Private key", re.compile(r"-----BEGIN [A-Z ]*PRIVATE KEY-----")),
]

_log_path = None


# --------------------------------------------------------------------------
# Logging
# --------------------------------------------------------------------------


def log(msg, to_file=True):
    line = f"{datetime.now():%Y-%m-%d %H:%M:%S} {msg}"
    try:
        print(line)
    except UnicodeEncodeError:
        print(line.encode("ascii", "replace").decode("ascii"))
    if to_file and _log_path is not None:
        try:
            with open(_log_path, "a", encoding="utf-8") as f:
                f.write(line + "\n")
        except OSError:
            pass


def trim_log(path):
    try:
        if path.exists() and path.stat().st_size > LOG_MAX_BYTES:
            data = path.read_text(encoding="utf-8", errors="replace")
            path.write_text(data[-(LOG_MAX_BYTES // 2) :], encoding="utf-8")
    except OSError:
        pass


# --------------------------------------------------------------------------
# git helpers
# --------------------------------------------------------------------------


def git(repo, *args, input_bytes=None, timeout=GIT_TIMEOUT, literal=True):
    env = dict(os.environ, GIT_TERMINAL_PROMPT="0", GCM_INTERACTIVE="never")
    base = ["git", "-c", "core.quotepath=false"]
    if literal:  # file names like "a[1].cpp" must not be treated as patterns
        base.append("--literal-pathspecs")
    p = subprocess.run(
        [*base, "-C", str(repo), *args],
        input=input_bytes,
        capture_output=True,
        timeout=timeout,
        env=env,
        creationflags=NO_WINDOW,
    )
    return (
        p.returncode,
        p.stdout.decode("utf-8", "replace"),
        p.stderr.decode("utf-8", "replace"),
    )


def pending_changes(repo):
    """[(XY status, path)] for everything git sees as new/changed/deleted."""
    rc, out, err = git(repo, "status", "--porcelain=v1", "-z", "--untracked-files=all")
    if rc != 0:
        raise RuntimeError(f"git status failed: {err.strip()[:300]}")
    toks = out.split("\0")
    entries, i = [], 0
    while i < len(toks):
        t = toks[i]
        i += 1
        if len(t) < 4:
            continue
        xy, path = t[:2], t[3:]
        if xy[0] in "RC":
            i += 1  # skip the original path of a rename/copy
        if path in OWN_FILES:
            continue  # never commit our own log/lock, even if .gitignore lacks them
        entries.append((xy, path))
    return entries


def is_blank(path):
    try:
        size = path.stat().st_size
        if size == 0:
            return True
        if size > 4096:
            return False
        return path.read_bytes().decode("utf-8", "replace").strip() == ""
    except OSError:
        return False


def classify(repo, entries, settle):
    """Split pending changes into files to upload and counts of what was skipped."""
    now = time.time()
    upload, skipped = [], {"blank": 0, "emptied": 0, "recent": 0, "too big": 0}

    for xy, path in entries:
        full = repo / path
        if not full.exists():
            if "D" in xy:  # deleted file: commit the deletion
                upload.append(path)
            continue
        if full.is_dir():
            continue
        if is_blank(full):
            skipped["blank" if xy == "??" else "emptied"] += 1
            continue
        try:
            st = full.stat()
        except OSError:
            continue
        if st.st_size > MAX_FILE_BYTES:
            skipped["too big"] += 1
            continue
        if settle and now - st.st_mtime < settle:
            skipped["recent"] += 1
            continue
        upload.append(path)

    return upload, skipped


def scan_for_secrets(repo, paths):
    """{path: reason} for files whose content looks like it contains a secret."""
    blocked = {}
    for path in paths:
        full = repo / path
        try:
            if not full.is_file() or full.stat().st_size > MAX_FILE_BYTES:
                continue
            text = full.read_bytes().decode("utf-8", "replace")
        except OSError:
            continue
        for reason, rx in SECRET_PATTERNS:
            if rx.search(text):
                blocked[path] = reason
                break
    return blocked


def tracked_but_ignored(repo):
    """Tracked files that now match .gitignore (e.g. a folder you added to it later)."""
    rc, out, _ = git(repo, "ls-files", "-z", "-ci", "--exclude-standard")
    if rc != 0:
        return []
    return [p for p in out.split("\0") if p]


def untrack(repo, paths):
    """Remove files from the repo index only (they stay on disk and in history)."""
    payload = b"\0".join(p.encode("utf-8") for p in paths) + b"\0"
    rc, out, err = git(
        repo,
        "rm",
        "--cached",
        "-q",
        "--ignore-unmatch",
        "--pathspec-from-file=-",
        "--pathspec-file-nul",
        input_bytes=payload,
    )
    return "" if rc == 0 else short_error(err or out)


def ignored_among(repo, paths):
    """Subset of paths that match .gitignore rules (tracked or not)."""
    if not paths:
        return set()
    payload = b"\0".join(p.encode("utf-8") for p in paths) + b"\0"
    # check-ignore does not accept --literal-pathspecs (it takes plain paths anyway)
    rc, out, _ = git(
        repo,
        "check-ignore",
        "-z",
        "--stdin",
        "--no-index",
        input_bytes=payload,
        literal=False,
    )
    if rc not in (0, 1):
        return set()
    return {p for p in out.split("\0") if p}


def short_error(text):
    """One-line git error without the 'hint:' chatter."""
    lines = [
        l.strip() for l in text.splitlines() if l.strip() and not l.startswith("hint:")
    ]
    return " ".join(lines)[:300]


def stage(repo, paths):
    """
    git add the given paths. If the batch is refused, retry one by one so a
    single bad path can never block everything else. Returns {path: reason}
    for the files that could not be staged.
    """
    payload = b"\0".join(p.encode("utf-8") for p in paths) + b"\0"
    rc, out, err = git(
        repo,
        "add",
        "-A",
        "--pathspec-from-file=-",
        "--pathspec-file-nul",
        input_bytes=payload,
    )
    if rc == 0:
        return {}
    failed = {}
    for p in paths:
        rc, out, err = git(repo, "add", "-A", "--", p)
        if rc != 0:
            failed[p] = short_error(err or out)
    return failed


def staged_summary(repo):
    """[(letter, path)] of what is currently staged."""
    rc, out, _ = git(repo, "diff", "--cached", "--name-status", "-z", "--no-renames")
    toks = [t for t in out.split("\0") if t != ""]
    return list(zip(toks[0::2], toks[1::2]))


def commit_message(changes):
    a = sum(1 for s, _ in changes if s == "A")
    m = sum(1 for s, _ in changes if s == "M")
    d = sum(1 for s, _ in changes if s == "D")
    parts = []
    if a:
        parts.append(f"{a} new")
    if m:
        parts.append(f"{m} updated")
    if d:
        parts.append(f"{d} removed")
    title = "Sync: " + (", ".join(parts) or "changes")
    body = [f"{s} {p}" for s, p in changes[:30]]
    if len(changes) > 30:
        body.append(f"... and {len(changes) - 30} more")
    return title, "\n".join(body)


def push_if_needed(repo):
    """Returns (status, detail). status: pushed / up-to-date / no-remote / no-commits / failed."""
    rc, remotes, _ = git(repo, "remote")
    if "origin" not in remotes.split():
        return "no-remote", ""
    rc, _, _ = git(repo, "rev-parse", "--verify", "-q", "HEAD")
    if rc != 0:
        return "no-commits", ""

    rc, _, _ = git(repo, "rev-parse", "--abbrev-ref", "--symbolic-full-name", "@{u}")
    if rc != 0:
        args = ["push", "-q", "-u", "origin", "HEAD"]
    else:
        rc, n, _ = git(repo, "rev-list", "--count", "@{u}..HEAD")
        if n.strip() in ("", "0"):
            return "up-to-date", ""
        args = ["push", "-q", "origin", "HEAD"]

    try:
        rc, out, err = git(repo, *args, timeout=PUSH_TIMEOUT)
    except subprocess.TimeoutExpired:
        return "failed", "push timed out"
    if rc != 0:
        return "failed", " ".join((err or out).split())[:400]
    return "pushed", ""


# --------------------------------------------------------------------------
# Lock (so two runs never overlap)
# --------------------------------------------------------------------------


def acquire_lock(repo):
    lock = repo / ".git_sync.lock"
    for _ in range(2):
        try:
            fd = os.open(str(lock), os.O_CREAT | os.O_EXCL | os.O_WRONLY)
            os.write(fd, str(os.getpid()).encode())
            os.close(fd)
            return lock
        except FileExistsError:
            try:
                age = time.time() - lock.stat().st_mtime
            except OSError:
                continue
            if age > LOCK_STALE_SECONDS:
                try:
                    lock.unlink()
                except OSError:
                    return None
                continue
            return None
        except OSError:
            return None
    return None


# --------------------------------------------------------------------------
# Main entry point
# --------------------------------------------------------------------------


def run(repo=REPO, dry_run=False, settle=SETTLE_SECONDS, push=True):
    """Do one sync. Returns a result dict (see exit_code)."""
    global _log_path
    repo = Path(repo)
    _log_path = None if dry_run else repo / "git_sync.log"
    if _log_path:
        trim_log(_log_path)

    result = {
        "candidates": [],
        "blocked": {},
        "skipped": {},
        "committed": 0,
        "push": "",
        "errors": [],
        "locked": False,
        "changes": [],
    }

    if not (repo / ".git").exists():
        log("This folder is not a git repo yet. Run git_setup.py first.")
        result["errors"].append("not a repo")
        return result

    lock = None
    if not dry_run:
        lock = acquire_lock(repo)
        if lock is None:
            log("Another sync is still running (lock file). Skipping this run.")
            result["locked"] = True
            return result

    try:
        _sync(repo, dry_run, settle, push, result)
    except subprocess.TimeoutExpired:
        log("A git command timed out.")
        result["errors"].append("timeout")
    except Exception as e:
        log(f"ERROR: {type(e).__name__}: {e}")
        result["errors"].append(str(e))
    finally:
        if lock is not None:
            try:
                lock.unlink()
            except OSError:
                pass
    return result


def _sync(repo, dry_run, settle, push, result):
    # Tracked files that now match .gitignore (a folder you ignored later):
    # stop tracking them. They stay on your PC and in git history.
    stale = tracked_but_ignored(repo)
    result["untracked"] = len(stale)
    if stale and not dry_run:
        problem = untrack(repo, stale)
        if problem:
            log(f"Could not stop tracking ignored files: {problem}")
            result["errors"].append("untrack failed")
        else:
            log(
                f"Stopped tracking {len(stale)} file(s) that are now in .gitignore "
                "(still on your PC and in git history)."
            )

    entries = pending_changes(repo)
    upload, skipped = classify(repo, entries, settle)
    hidden = ignored_among(repo, upload)
    if hidden:
        upload = [p for p in upload if p not in hidden]
        skipped["ignored"] = skipped.get("ignored", 0) + len(hidden)
    blocked = scan_for_secrets(repo, upload)
    upload = [p for p in upload if p not in blocked]
    skipped = {k: v for k, v in skipped.items() if v}

    result["candidates"], result["blocked"], result["skipped"] = (
        upload,
        blocked,
        skipped,
    )

    for path, reason in blocked.items():
        log(f"BLOCKED (looks like a secret: {reason}): {path}")

    if dry_run:
        if stale:
            print(
                f"Would stop tracking {len(stale)} file(s) that are now in .gitignore."
            )
        print(f"Would commit {len(upload)} file(s).")
        for p in upload[:40]:
            print(f"  {p}")
        if len(upload) > 40:
            print(f"  ... and {len(upload) - 40} more")
        if skipped:
            print("Not included: " + ", ".join(f"{v} {k}" for k, v in skipped.items()))
        return

    if upload:
        failed = stage(repo, upload)
        for path, why in failed.items():
            log(f"Could not stage {path}: {why}")
        if failed:
            result["errors"].append(f"could not stage {len(failed)} file(s)")

    # Commit whatever is staged (this also covers removals from untracking).
    changes = staged_summary(repo)
    if changes:
        title, body = commit_message(changes)
        rc, out, err = git(repo, "commit", "-q", "-m", title, "-m", body)
        if rc != 0:
            msg = (err or out).strip()
            if "tell me who you are" in msg or "user.email" in msg:
                msg = "git has no name/email set. Run git_setup.py again."
            raise RuntimeError(f"git commit failed: {msg[:300]}")
        result["committed"] = len(changes)
        result["changes"] = changes
        log(f"Committed: {title}")

    if skipped and result["committed"]:
        log("Not included: " + ", ".join(f"{v} {k}" for k, v in skipped.items()))

    if push:
        status, detail = push_if_needed(repo)
        result["push"] = status
        if status == "pushed":
            log("Pushed to GitHub.")
        elif status == "failed":
            log(f"PUSH FAILED (will retry next run): {detail}")
            result["errors"].append("push failed")
        elif status == "no-remote":
            log("No GitHub remote configured, nothing pushed.", to_file=False)

    if not result["committed"] and not result["push"] == "pushed":
        log("Nothing to sync.", to_file=False)


def exit_code(result):
    if result["errors"]:
        return 1
    if result["blocked"]:
        return 2
    return 0


def main():
    ap = argparse.ArgumentParser(description="Commit and push new solutions.")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--no-push", action="store_true")
    ap.add_argument(
        "--settle",
        type=int,
        default=SETTLE_SECONDS,
        help="skip files modified in the last N seconds (default 60)",
    )
    args = ap.parse_args()
    result = run(REPO, dry_run=args.dry_run, settle=args.settle, push=not args.no_push)
    sys.exit(exit_code(result))


if __name__ == "__main__":
    main()
