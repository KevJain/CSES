import subprocess
import threading
import sys
import random

MAX_NUM = 10**18
LIMIT = 150
def read_cerr(cerr): 
    for line in iter(cerr.readline, ''):
        print(f"[CERR]: {line}", end='')
    cerr.close()


def writeline(process, s):
    process.stdin.write(s + "\n")
    process.stdin.flush()

def generate_cases(n):
    out = []
    for _ in range(n):
        here = [MAX_NUM]
        here.append(random.randint(1, MAX_NUM))
        here.append(random.randint(1, MAX_NUM))
        here.append(random.randint(1, MAX_NUM))
        out.append(here)
    return out

def main():
    print("Executing C++ Program")
    #test_cases = [[3,1,2,3],[6,2,3,5],[1000000000000000000, 74859962623690085, 74859962623690086, 74859962623690087]]
    #test_cases = [[MAX_NUM, 40404483312305495, 573946969672374907, 991921405683159865]]
    test_cases = [[MAX_NUM, 517644270349535956, 607760074044589219, 627224147332285010]]
    # Call C program
    #test_cases = generate_cases(1000);
    process = subprocess.Popen(["./a.out"],
                                stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                text = True
                                )
    writeline(process, str(len(test_cases)))
    thread = threading.Thread(target=read_cerr, args=(process.stderr,))
    thread.daemon = True
    #thread.start()

    for test in test_cases:
        n, a, b, c = test
        ans = [a,b,c]
        ans.sort()
        writeline(process, str(n))
        
        for _ in range(LIMIT):
            output = process.stdout.readline() # get guess
            output.strip()
            #print(f"[COUT]: {output}", end="")
            args = output.split()
            if args[0] == "ans":
                guess = [int(m) for m in args[1:]]
                guess.sort()
                if ans == guess:
                    print(f"Returned {guess}, correct")
                    pass
                else:
                    print(f"Returned {guess}, incorrect for case {n} {ans}")
                    pass
                break
            elif args[0] == "xor":
                l = int(args[1])
                r = int(args[2])
                if l > r or r > MAX_NUM:
                    print(f"guess out of bounds {l} {r} for case {n} {ans}")
                out_xor = 0
                for num in ans:
                    if l <= num <= r:
                        out_xor ^= num
                #print(f"Returning xor: {out_xor}")
                writeline(process, str(out_xor))

    print("done")
main()

"""
guess out of bounds 1 100 for case 100 [44701077118991007, 199482315198018082, 496416445936365935]
guess out of bounds 1 63 for case 100 [44701077118991007, 199482315198018082, 496416445936365935]
guess out of bounds 1 31 for case 100 [44701077118991007, 199482315198018082, 496416445936365935]
guess out of bounds 1 15 for case 100 [44701077118991007, 199482315198018082, 496416445936365935]
guess out of bounds 1 7 for case 100 [44701077118991007, 199482315198018082, 496416445936365935]
guess out of bounds 1 3 for case 100 [44701077118991007, 199482315198018082, 496416445936365935]
"""
