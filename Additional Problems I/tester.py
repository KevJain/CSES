import subprocess
import threading
import sys
import random

MAX_NUM = 15
LIMIT = 150
def read_cerr(cerr): 
    for line in iter(cerr.readline, ''):
        print(f"[CERR]: {line}", end='')
    cerr.close()


def writeline(process, s):
    process.stdin.write(s + "\n")
    process.stdin.flush()

def generate_cases(n, k):
    out = []
    for _ in range(n):
        here = []
        for _ in range(k):
            here.append(random.randint(1, MAX_NUM))
        out.append(here)
    return out

def run_prog(name, case):
    process = subprocess.Popen([name],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                text = True
                                )
    writeline(process, str(len(case)))
    writeline(process, to_in_str(case))
    res = int(process.stdout.readline().strip())
    return res

def to_in_str(arr):
    return " ".join([str(e) for e in arr])

def main():
    print("Executing C++ Program")
    subprocess.run(["g++-15", "Advertisement.cpp", "-o", "cand"])
    subprocess.run(["g++-15", "AdvertisementSmall.cpp", "-o", "checker"])
    cases = generate_cases(10, 10)
    for case in cases:
        cand_out = run_prog("./cand", case)
        checker_out = run_prog("./checker", case)
        if (cand_out != checker_out):
            s = to_in_str(case)
            print(f"Failed test case {s}")
            print(f"Expected {checker_out}, got {cand_out}")


    print("done")
main()
