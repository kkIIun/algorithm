import sys

input = sys.stdin.readline
INF = sys.maxsize

n = int(input())
m = int(input())
Map = [[INF] * n for _ in range(n)]

for _ in range(m):
    start, end, cost = map(int, input().split())
    Map[start - 1][end - 1] = min(Map[start - 1][end - 1], cost)

for i in range(n):
    for j in range(n):
        for k in range(n):
            if j == i or k == i or j == k:
                continue

            Map[j][k] = min(Map[j][k], Map[j][i] + Map[i][k])

for i in range(n):
    for j in range(n):
        if Map[i][j] == INF:
            Map[i][j] = 0

for i in range(n):
    for j in range(n):
        print(Map[i][j], end=" ")
    print()