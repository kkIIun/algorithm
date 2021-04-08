import math

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    if k >= n:
        print(1)

    else:
        ans = n
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                if i <= k:
                    ans = min(ans, n // i)
                if n // i <= k:
                    ans = min(ans, i)

        print(anss)
