n = int(input())
if n == 1:
    print(1)
elif n <= 3:
    print("NO SOLUTION")
else:
    print(" ".join([str(2 * i) for i in range(1, n//2 + 1)] + [str(2 * i + 1) for i in range((n+1)//2)]))