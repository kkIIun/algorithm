import math

t = int(input())

for _ in range(t):
    n = int(input())

    p = 0
    for i in range(2, int(math.sqrt(n)) + 1):

        if n % i == 0:
            p = i
            break
    if p:
        print(n // p, n - n // p)
    else:
        print(1, n - 1)
