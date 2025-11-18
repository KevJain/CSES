from functools import reduce
n = int(input())
candy = [int(w) for w in input().split()]
num = 0
prod = reduce(lambda x, y: x*y, candy, 1)
denom = 2 * prod
for i in range(n):
    for j in range(i+1, n):
        if candy[i] <= candy[j]:
            num += (prod // candy[j]) * (candy[i] - 1)
        else:
            num += (prod // candy[i]) * (2 * candy[i] - candy[j] - 1)

out = 0
rem = num
place = 4 # power of 10, will evaluate until place = -6
while (place >= -6):
    placed = num * (10 ** -place) // denom
    out += 10 ** place * (placed)
    num = num - 10

print(out)
print(f'{out:.6f}')
