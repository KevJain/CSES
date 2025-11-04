import sys
def main():
    s = input()
    run_len = 0
    cur_char = ""
    max_len = 0
    for c in s:
        if c == cur_char:
            run_len += 1
        else:
            max_len = max(max_len, run_len)
            cur_char = c
            run_len = 1
    print(max(max_len, run_len))
main()