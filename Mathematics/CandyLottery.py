n, k = [int(w) for w in input().split()]
res = k - sum(i**n for i in range(k))/(k**n)
print(f"{res:.6f}")
