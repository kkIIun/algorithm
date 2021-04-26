import math

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]

    peak = [0] * n
    for i in range(1, len(a) - 1):
        if a[i - 1] < a[i] and a[i + 1] < a[i]:
            peak[i] = 1

    for i in range(1, len(a) - 1):
        peak[i] += peak[i - 1]

    ans, l = -1, 0
    for i in range(n - k + 1):
        if ans < peak[i + k - 2] - peak[i]:
            ans = peak[i + k - 2] - peak[i]
            l = i + 1

    print(ans + 1, l)
