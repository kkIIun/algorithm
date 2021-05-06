t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    arr = [int(x) for x in input().split()]
    dict = {}
    cnt = 0

    for i in range(n):
        if arr[i] not in dict:
            dict[arr[i]] = 1
            cnt += 1

    if cnt > k:
        print(-1)

    else:
        Common_arr = arr[:k]
        ans = []
        while len(ans) < len(arr) + 1:
            ans += Common_arr

        print(len(ans))
        print(ans)