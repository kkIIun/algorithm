import sys
from collections import deque

input = sys.stdin.readline
INF = sys.maxsize

move = [(0, 1), (1, 0), (0, -1), (-1, 0)]
n, m, k = map(int, input().split())
graph = [list(input()) for _ in range(n)]
word = list(input().strip())
lw = len(word)
dp = [[[-1] * lw for _ in range(m)] for _ in range(n)]


def setMove():
    for i in range(1, k):
        for j in range(4 * (i - 1), 4 * i):
            y, x = move[j][0] + move[j % 4][0], move[j][1] + move[j % 4][1]
            move.append((y, x))


def check(ny, nx):
    return ny < 0 or nx < 0 or ny >= n or nx >= m


def dfs(y, x, index):
    if index == lw:
        return 1

    if dp[y][x][index] != -1:
        return dp[y][x][index]

    dp[y][x][index] = 0
    for i in range(len(move)):
        ny, nx = y + move[i][0], x + move[i][1]
        if check(ny, nx) or graph[ny][nx] != word[index]:
            continue

        dp[y][x][index] += dfs(ny, nx, index + 1)

    return dp[y][x][index]


setMove()
ans = 0
for i in range(n):
    for j in range(m):
        if graph[i][j] == word[0]:
            ans += dfs(i, j, 1)


print(ans)
