t = int(input())

for _ in range(t):
    n = int(input())
    arr = [list(map(int, input())) for _ in range(n)]
    ans = 0
    for i in range(n - 1):
        for j in range(n - 1):
            if arr[i][j] == 1 and arr[i][j + 1] == 0 and arr[i + 1][j] == 0:
                ans += 1

    if ans:
        print("NO")
    else:
        print("YES")