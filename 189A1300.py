n, a, b, c = map(int, input().split())
x, y, z = -1, -1, -1
dp = [None] * (n + 1)
dp[0] = 0

for i in range(1, len(dp)):
    if i >= a:
        x = dp[i - a]

    if i >= b:
        y = dp[i - b]

    if i >= c:
        z = dp[i - c]

    if x == -1 and y == -1 and c == -1:
        dp[i] = -1

    else:
        dp[i] = max(x, y, z) + 1

if dp[n] == -1:
    print("error")

else:
    print(dp[n])
