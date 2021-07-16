import sys
from collections import deque

input = sys.stdin.readline
INF = sys.maxsize


def dfs(current, visited):
    if visited == (1 << n) - 1:
        return graph[current][0] or INF

    if dp[current][visited] != INF:
        return dp[current][visited]

    for city in range(n):
        if not (visited & 1 << city) and graph[current][city] != 0:
            dp[current][visited] = min(
                dp[current][visited], dfs(city, visited | (1 << city)) + graph[current][city]
            )

    return dp[current][visited]


n = int(input())
graph = [[int(x) for x in input().split()] for _ in range(n)]
dp = [[INF] * (1 << n) for _ in range(n)]


print(dfs(0, 1 << 0))
