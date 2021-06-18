import math

t = int(input())

for _ in range(t):
    n = int(input())
    cnt = 0
    a, b, c, i = 0, 0, 0, 2
    while int(math.sqrt(n)) >= i:
        if n % i == 0 and cnt == 0:
            a = i
            n = n // i
            cnt = 1
        elif n % i == 0 and cnt == 1 and n // i > i:
            b, c = i, n // i
        i += 1
    if c == 0:
        print("NO")
    else:
        print("YES")
        print(a, b, c)
