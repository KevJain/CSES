k = int(input())
sz = 8
board = [[1.0 for _ in range(sz)] for _ in range(sz)]

dirs = [(-1,0),(1,0),(0,-1),(0,1)]

dir_count = [[4.0 for _ in range(sz)] for _ in range(sz)]
for i in range(sz):
    dir_count[i][0] -= 1.0
    dir_count[0][i] -= 1.0
for i in range(sz-1,-1,-1):
    dir_count[i][sz-1] -= 1.0
    dir_count[sz-1][i] -= 1.0

#dp[i][k][row][col] = probability that robot i is in (row,col) after k moves
#size: 64*k*64

dp = [[[[0.0 for _ in range(sz)] for _ in range(sz)] for _ in range(k+1)] for _ in range(sz*sz)]

for robot in range(sz*sz):
    dp[robot][0][robot//sz][robot%sz] = 1.0 # start pos
    for step in range(k):
        for row in range(sz):
            for col in range(sz):
                for dr, dc in dirs:
                    nr, nc = row+dr, col+dc
                    if 0 <= nr < sz and 0 <= nc < sz:
                        dp[robot][step+1][nr][nc] += 1/dir_count[row][col] * dp[robot][step][row][col]

out = 0.0

for row in range(sz):
    for col in range(sz):
        empty = 1.0
        for robot in range(sz*sz):
            empty *= (1-dp[robot][k][row][col])
        out += empty

print(f"{out:.6f}")

#n, k = [int(w) for w in input().split()]
#res = k - sum(i**n for i in range(k))/(k**n)
#print(f"{res:.6f}")
