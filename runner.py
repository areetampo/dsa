import subprocess
import os
import time
import glob
import sys

# --- Validate input ---
if len(sys.argv) < 2:
    msg = "Usage: py runner.py <filename.cpp>"
    print(msg)
    open("compile_dbg.txt", "w").write(msg)
    sys.exit(1)

CPP = sys.argv[1]

if not CPP.endswith(".cpp"):
    msg = f"Error: '{CPP}' is not a .cpp file."
    print(msg)
    open("compile_dbg.txt", "w").write(msg)
    sys.exit(1)

if not os.path.exists(CPP):
    msg = f"Error: File '{CPP}' not found."
    print(msg)
    open("compile_dbg.txt", "w").write(msg)
    sys.exit(1)

# --- Compile ---
EXE = CPP.replace(".cpp", ".exe")
print(f"Compiling {CPP} ...")

res = subprocess.run(
    ["g++", "-std=c++23", "-O2", CPP, "-o", EXE], stderr=subprocess.PIPE, text=True
)

if res.returncode != 0:
    open("compile_dbg.txt", "w").write(res.stderr)
    print("Compile error. See compile_dbg.txt")
    sys.exit()

# --- Find tests ---
tests = sorted(glob.glob("tests/*.in"))

if not tests:
    print("No test files found in 'tests/' folder.")
    sys.exit()

os.makedirs("outputs", exist_ok=True)
os.makedirs("dbg", exist_ok=True)

print("\nRunning tests\n")

for f in tests:
    name = os.path.basename(f).split(".")[0]
    dbg_file_path = f"dbg/{name}.txt"
    result = None

    start = time.time()

    try:
        with open(dbg_file_path, "w") as dbg_out:
            subprocess.run(
                [EXE],
                stdin=open(f),
                stdout=open(f"outputs/{name}.out", "w"),
                stderr=dbg_out,
                timeout=2,
            )

        runtime = (time.time() - start) * 1000

        # Read expected and actual outputs as lines (preserving internal spaces)
        with open(f"tests/{name}.out") as exp_file:
            expected_lines = [line.rstrip() for line in exp_file.read().splitlines()]
        with open(f"outputs/{name}.out") as out_file:
            output_lines = [line.rstrip() for line in out_file.read().splitlines()]

        if expected_lines == output_lines:
            result = f"[PASS] Test {name} ({runtime:.1f} ms)"
            print(result)
            with open(dbg_file_path, "a") as dbg_out:
                dbg_out.write(result + "\n")
        else:
            result = f"[WA] Test {name}"
            print(result)

            # Build detailed mismatch info
            detail = []
            if len(expected_lines) != len(output_lines):
                detail.append(
                    f"Length mismatch: expected {len(expected_lines)} lines, got {len(output_lines)} lines."
                )

            # Find first differing line
            for i, (e_line, o_line) in enumerate(zip(expected_lines, output_lines)):
                if e_line != o_line:
                    detail.append(f"First mismatch at line {i+1}:")
                    detail.append(f"  Expected: {e_line}")
                    detail.append(f"  Got:      {o_line}")
                    break
            else:
                # If lengths differ but all matched lines are equal
                if len(expected_lines) != len(output_lines):
                    # Already handled length mismatch above
                    pass
                else:
                    # Should not happen, but just in case
                    detail.append(
                        "Outputs differ but no line mismatch found (unexpected)."
                    )

            # Write to dbg file
            with open(dbg_file_path, "a") as dbg_out:
                dbg_out.write(result + "\n")
                dbg_out.write("\n".join(detail) + "\n")

    except subprocess.TimeoutExpired:
        result = f"[TLE] Test {name}"
        print(result)
        with open(dbg_file_path, "a") as dbg_out:
            dbg_out.write("(timeout)\n")
            dbg_out.write(result + "\n")
