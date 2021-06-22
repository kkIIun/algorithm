def mul(a, b):
    tmp = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            for z in range(n):
                tmp[i][j] += a[i][z] * b[z][j]
            tmp[i][j] %= mod

    return tmp


def Pow(a, b):
    if b == 1:
        return a

    elif b % 2:
        c = Pow(a, b - 1)
        return mul(c, a)

    c = Pow(a, b // 2)
    return mul(c, c)


mod = 1000
n, b = map(int, input().split())
arr = [[int(x) for x in input().split()] for i in range(n)]
for i in range(n):
    for j in range(n):
        arr[i][j] %= mod
arr = Pow(arr, b)
for i in range(n):
    Str = ""
    for j in range(n):
        Str += str(arr[i][j]) + " "
    print(Str)