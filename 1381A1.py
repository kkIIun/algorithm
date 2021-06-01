t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input()))
    b = list(map(int, input()))

    ans = 0
    string = ""
    k = len(a) - 1
    while a != b:
        for i in range(k, 0 - 1, -1):
            if a[i] != b[i]:
                k = i
                break

        if a[0] == b[k]:
            ans += 1
            if a[0] == 0:
                a[0] = 1
            else:
                a[0] = 0
            string += "1 "

        ans += 1
        string += str(k + 1) + " "
        for i in range(k + 1):
            if a[i] == 0:
                a[i] = 1
            else:
                a[i] = 0
        a = a[: k + 1][::-1] + a[k + 1 :]

    print(str(ans) + " "+ string)
