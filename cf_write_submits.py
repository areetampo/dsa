"""
Manual restore helper (Windows). Does NOT talk to Codeforces.

For each unfinished submission in urls.txt:
  1. Open the URL in your normal browser and copy the code
     (click in the source box, Ctrl+A, Ctrl+C).
  2. Come back here and press ENTER ONLY. Do NOT paste into this window.
     The script reads the clipboard itself.

Prompt keys:  Enter = save clipboard   s = skip   q = quit

Usage:
  python cf_helper.py          # up to 15 per session
  python cf_helper.py 5        # up to 5 per session
"""

import ctypes
import sys
import time
from ctypes import wintypes
from pathlib import Path

ROOT = Path(r"C:\Iris\dsa")
URLS_FILE = ROOT / "urls.txt"
SUCCESS_LOG = ROOT / "restore_success.log"

DEFAULT_BATCH = 15

# ---------------------------------------------------------------------------
# Clipboard (Win32 API, with retries: browsers and Win+V history can briefly
# hold the clipboard lock, which made the old tkinter version report "empty").
# ---------------------------------------------------------------------------

CF_UNICODETEXT = 13

user32 = ctypes.WinDLL("user32", use_last_error=True)
kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)

user32.OpenClipboard.argtypes = [wintypes.HWND]
user32.OpenClipboard.restype = wintypes.BOOL
user32.CloseClipboard.argtypes = []
user32.CloseClipboard.restype = wintypes.BOOL
user32.GetClipboardData.argtypes = [wintypes.UINT]
user32.GetClipboardData.restype = wintypes.HANDLE
kernel32.GlobalLock.argtypes = [wintypes.HGLOBAL]
kernel32.GlobalLock.restype = wintypes.LPVOID
kernel32.GlobalUnlock.argtypes = [wintypes.HGLOBAL]
kernel32.GlobalUnlock.restype = wintypes.BOOL


def read_clipboard(retries: int = 30, delay: float = 0.1):
    """Return (text, error). error is None on success."""
    opened = False
    for _ in range(retries):
        if user32.OpenClipboard(None):
            opened = True
            break
        time.sleep(delay)

    if not opened:
        return None, "could not open the clipboard (another app is holding it)"

    try:
        handle = user32.GetClipboardData(CF_UNICODETEXT)
        if not handle:
            return None, "the clipboard has no text on it (is it an image or file?)"

        ptr = kernel32.GlobalLock(handle)
        if not ptr:
            return None, "could not read the clipboard memory"

        try:
            return ctypes.wstring_at(ptr), None
        finally:
            kernel32.GlobalUnlock(handle)
    finally:
        user32.CloseClipboard()


# ---------------------------------------------------------------------------


def norm(p: str) -> str:
    return p.strip().replace("\\", "/")


def read_lines(path: Path):
    if not path.exists():
        return []
    return [
        l
        for l in path.read_text(encoding="utf-8", errors="replace").splitlines()
        if l.strip()
    ]


def flush_stdin():
    """Drop any pasted text still waiting in the terminal."""
    try:
        import msvcrt

        while msvcrt.kbhit():
            msvcrt.getwch()
    except ImportError:
        pass


def main():
    batch = int(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT_BATCH

    entries = []
    for l in read_lines(URLS_FILE):
        parts = l.split("\t")
        if len(parts) >= 2:
            entries.append((norm(parts[0]), parts[1].strip()))

    done = {norm(l.split("\t", 1)[0]) for l in read_lines(SUCCESS_LOG)}
    todo = [(p, u) for p, u in entries if p not in done]

    print(f"{len(done)} restored, {len(todo)} remaining.")
    if not todo:
        print("Nothing left to do.")
        return

    saved = 0
    last_saved_text = None
    quit_now = False

    for path, url in todo:
        if saved >= batch or quit_now:
            break

        print()
        print(f"[{saved + 1}/{min(batch, len(todo))}] {path}")
        print(f"  {url}")

        while True:
            choice = input(
                "  Copy the code in the browser, then press Enter " "(s=skip, q=quit): "
            )

            if choice.strip().lower() == "q":
                quit_now = True
                break
            if choice.strip().lower() == "s":
                break

            if choice != "":
                # Text was pasted into the terminal. Stop everything.
                flush_stdin()
                print(
                    "\n  You pasted text into the terminal. Don't paste here: "
                    "just press Enter after copying.\n  Stopping so nothing "
                    "is saved by mistake. Run the script again."
                )
                quit_now = True
                break

            text, error = read_clipboard()

            if error:
                print(f"  Problem: {error}. Try copying again.")
                continue

            if not text.strip():
                print("  Clipboard is empty. Copy the code first.")
                continue

            # The browser/Windows gives CRLF; earlier restored files used LF.
            text = text.replace("\r\n", "\n")

            if text == last_saved_text:
                print(
                    "  Clipboard is identical to the last saved file. "
                    "Copy the NEW submission first."
                )
                continue

            target = ROOT / path
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_text(text, encoding="utf-8", newline="")

            with SUCCESS_LOG.open("a", encoding="utf-8") as f:
                f.write(f"{path.replace('/', chr(92))}\t{url}\t{len(text)} chars\n")

            last_saved_text = text
            saved += 1
            print(f"  Saved ({len(text)} chars).")
            break

    print(f"\nSaved {saved} this session.")


if __name__ == "__main__":
    main()
