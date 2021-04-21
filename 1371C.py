t = int(input())

for _ in range(t):
    a, b, n, m = map(int, input().split())

    if a + b < n + m or min(a, b) < m:
        print("NO")
    else:
        print("YES")