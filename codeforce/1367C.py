t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    tables = list(map(int, input()))

    cnt, j = 0, 0
    while j < n:
        if tables[j] == 0:
            temp, check = 0, True
            while temp <= k and j < n:
                if tables[j] == 1:
                    check = False
                    j += k + 1
                    break
                j += 1
                temp += 1
            if check:
                cnt += 1
        else:
            j += k + 1

    print(cnt)
