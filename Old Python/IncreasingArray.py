import sys
def main():
    n = int(input())
    arr = list(map(int, input().split()))    
    diff = 0
    prev = arr[0]
    for i in range(1, len(arr)):
        cur = max(arr[i], prev)
        diff += max(0, cur - arr[i])
        prev = cur
    print(diff)
main()