import sys
import shutil
import os
import subprocess

if len(sys.argv) < 2:
    print("Usage: py new.py <problem_name>   (e.g., a  or  x/a)")
    exit()

path_arg = sys.argv[1]

# Split into folder and filename
if "/" in path_arg:
  folder, filename = os.path.split(path_arg)
  os.makedirs(folder, exist_ok=True)
else:
    # No slash: default folder = "dot"
    folder = "dot"
    filename = path_arg

# Ensure filename ends with .cpp
if not filename.endswith(".cpp"):
    filename += ".cpp"

# Create full path
target_dir = folder
os.makedirs(target_dir, exist_ok=True)
cpp_path = os.path.join(target_dir, filename)

if os.path.exists(cpp_path):
    print(f"File already exists: {cpp_path}")
    exit()

# Copy template.cpp (assumed to be in current directory)
if not os.path.exists("template.cpp"):
    print("Error: template.cpp not found in current directory.")
    exit()

shutil.copy("template.cpp", cpp_path)

# (Optional) Keep the original behavior of creating a tests folder in current directory
os.makedirs("tests", exist_ok=True)

print(f"Created: {cpp_path}")

# Open the file in VSCode
subprocess.run(["code", cpp_path])
