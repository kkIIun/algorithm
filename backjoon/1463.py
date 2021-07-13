import sys
from collections import deque

input = sys.stdin.readline
INF = sys.maxsize

n = int(input())
dp = [0] * 1000001

for i in range(2, n + 1):
    Min = INF
    if i % 2 == 0:
        Min = min(Min, dp[i // 2] + 1)

    if i % 3 == 0:
        Min = min(Min, dp[i // 3] + 1)

    dp[i] = min(Min, dp[i - 1] + 1)


print(dp[n])