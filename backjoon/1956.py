import sys
from collections import deque

input = sys.stdin.readline
INF = sys.maxsize


def floyid():
    for node in range(1, v + 1):
        for i in range(1, v + 1):
            for j in range(1, v + 1):
                if i == node or j == node:
                    continue
                dp[i][j] = min(dp[i][j], dp[i][node] + dp[node][j])


def getmin():
    val = INF
    for i in range(1, v + 1):
        val = min(val, dp[i][i])
    return val


v, e = map(int, input().split())
dp = [[INF for _ in range(v + 1)] for _ in range(v + 1)]
for _ in range(e):
    start, end, dist = map(int, input().split())
    dp[start][end] = dist

floyid()
ans = getmin()
print(ans if ans != INF else -1)