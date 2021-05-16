t = int(input())

for _ in range(t):
    s = list(input())
    o, z = 0, 0
    n = len(s)
    for i in range(n):
        if s[i] == "1":
            o += 1
        else:
            z += 1

    if o == n or z == n:
        print(0)

    elif s[0] == "1" and z == n - 1 or s[-1] == "1" and z == n - 1:
        print(0)

    elif s[0] == "0" and o == n - 1 or s[-1] == "0" and o == n - 1:
        print(0)

    else:
        a, b = 0, 0
        c = 99999999
        for i in range(n):
            if s[i] == "1":
                a += 1
            else:
                b += 1

            p = a + (z - b)
            q = b + (o - a)
            c = min(c, min(p, q))
        print(c)