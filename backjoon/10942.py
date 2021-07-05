import sys


def init():
    for i in range(n):
        dp[i][i] = 1

    for i in range(n - 1):
        if num[i] == num[i + 1]:
            dp[i][i + 1] = 1


n = int(input())
num = [int(x) for x in input().split()]
dp = [[0 for _ in range(n)] for _ in range(n)]

init()
for l in range(3, n + 1):
    for i in range(n + 1 - l):
        if dp[i + 1][i + l - 2] == 1 and num[i] == num[i + l - 1]:
            dp[i][i + l - 1] = 1

for _ in range(int(input())):
    s, e = [int(a) for a in sys.stdin.readline().split()]
    print(dp[s - 1][e - 1])
