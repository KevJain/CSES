from functools import reduce
from math import gcd

n = int(input())
candy = [int(w) for w in input().split()]
num = 0
prod = reduce(lambda x, y: x * y, candy, 1)
denom = 2 * prod
for i in range(n):
    for j in range(i + 1, n):
        if candy[i] <= candy[j]:
            num += (prod // candy[j]) * (candy[i] - 1)
        else:
            num += (prod // candy[i]) * (2 * candy[i] - candy[j] - 1)

g = gcd(num, denom)
num //= g
denom //= g
out = num / denom
mult = out * denom
print(int(out * 10000000))
if int(out * 10000000) % 10 == 5:
    print("t")
    if mult > num:
        out += 1e-7
    elif mult < num:
        out -= 1e-7
print(num, denom)
print(out)

print(f"{out:.6f}")
