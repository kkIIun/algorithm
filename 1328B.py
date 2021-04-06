t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    i = 1
    while k - i > 0:
        k -= i
        i += 1
    str = "a" * (n - i - 1) + "b"
    for j in range(1, i + 1):
        if j == i - k + 1:
            str += "b"
        else:
            str += "a"
    print(str)
