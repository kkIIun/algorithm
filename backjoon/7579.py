def solve():
    for i in range(n):
        for j in range(Sum+1):
            dp[i][j] = dp[i-1][j]
            if c[i] <= j :
                dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]] + a[i])

n, m = map(int, input().split())
a = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]
Sum = 0
for i in c :
    Sum += i
dp = [[0 for _ in range(Sum+1)] for _ in range(n)]
solve()
for i in range(Sum+1):
    if dp[n-1][i] >= m:
        print(i)
        break