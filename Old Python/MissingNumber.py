import sys
from functools import reduce

def main():
    n = int(input())
    arr = list(map(int, input().split(" "))) 
    print(n * (n + 1) // 2 - sum(arr))
main()