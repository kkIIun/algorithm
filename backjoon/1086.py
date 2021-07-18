import sys
from collections import deque
from math import gcd, factorial

input = sys.stdin.readline
INF = sys.maxsize


def dfs(L, visited, rest):

    if visited == (1 << n) - 1:
        return 1 if rest == 0 else 0

    if dp[visited][rest] != -1:
        return dp[visited][rest]

    dp[visited][rest] = 0
    for i in range(n):
        if (visited & (1 << i)) == 0:
            dp[visited][rest] += dfs(L + arr[i], visited | 1 << i, (rest + ten[i][L]) % k)

    return dp[visited][rest]


n = int(input())

arr = []
nums = []
for _ in range(n):
    num = list(input().strip())
    arr.append(len(num))
    nums.append(int("".join(num)))
k = int(input())
dp = [[-1 for _ in range(k)] for _ in range((1 << n))]

ten = [[-1] * (sum(arr)) for _ in range(n)]
for i in range(n):
    for j in range(sum(arr)):
        ten[i][j] = (nums[i] * 10 ** j) % k

p = dfs(0, 0, 0)
q = factorial(n)
if p == 0:
    print("0/1")
else:
    gcd = gcd(p, q)
    print("{}/{}".format(p // gcd, q // gcd))
