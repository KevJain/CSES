n, a, b = [int(w) for w in input().split()]

prob = [0.0] * (b+1)
prob[0] = 1.0

for _ in range(n):
    for s in range(b, -1, -1):
        prob[s] = 0.0
        for roll in range(1,7):
            if s - roll >= 0:
                prob[s] += prob[s-roll] * 1/6

out = sum(prob[a:])

print(f"{out:.6f}")

#n, k = [int(w) for w in input().split()]
#res = k - sum(i**n for i in range(k))/(k**n)
#print(f"{res:.6f}")
