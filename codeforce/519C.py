n, m = map(int, input().split())

ans = 0
while n > 0 and m > 0:
    if n > m:
        m -= 1
        n -= 2
        ans += 1

    elif n == 1 and m == 1:
        break

    else:
        n -= 1
        m -= 2
        ans += 1

print(ans)