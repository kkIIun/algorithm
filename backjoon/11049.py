matrix = []
n = int(input())
for _ in range(n):
    left, right = map(int, input().split())
    matrix.append([left, right])

dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
for l in range(1, n):
    for i in range(1, n - l + 1):
        dp[i][i + l] = min(
            (
                dp[i][mid]
                + dp[mid + 1][i + l]
                + matrix[mid - 1][1] * matrix[i + l - 1][1] * matrix[i - 1][0]
            )
            for mid in range(i, i + l)
        )

print(dp[1][n])