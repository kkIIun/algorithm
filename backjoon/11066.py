for _ in range(int(input())):
    k = int(input())
    dp = [[0 for _ in range(k + 1)] for _ in range(k + 1)]

    Sum = [int(x) for x in input().split()]
    Sum = [0] + Sum[:]
    for i in range(1, k + 1):
        Sum[i] += Sum[i - 1]

    for l in range(1, k):
        for i in range(1, k + 1 - l):
            dp[i][i + l] = min([dp[i][mid] + dp[mid + 1][i + l] for mid in range(i, i + l)]) + (
                Sum[i + l] - Sum[i - 1]
            )

    print(dp[1][k])