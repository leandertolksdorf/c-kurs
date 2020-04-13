import sys
import subprocess

# SETTINGS

def main(filename):
    subprocess.call(["gcc", filename, "-o", "xyz.out"])
    print("Compiled to " + filename + ".out")

if __name__ == "__main__":
    main(sys.argv[0])