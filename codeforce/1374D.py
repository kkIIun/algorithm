import math

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    a.sort()
    ans = 0
    while a:
        l, r = 0, len(a) - 1
        while l <= r:
            m = round((l + r) / 2)
            if a[m] == (k - ans) + k * (ans // k):
                a.pop(m)
                break
            elif a[m] > (k - ans) + k * (ans // k):
                r -= 1
            else:
                l += 1

        ans += 1

    print(ans)
