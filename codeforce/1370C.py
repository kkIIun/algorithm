import math


def isprime(n):
    for i in range(2, int(math.pow(n, 0.5)) + 1):
        if n % i == 0:
            return False
    return True


t = int(input())

for _ in range(t):

    n = int(input())
    m = 1

    while n % 2 == 0:
        n //= 2
        m *= 2

    if (m == 2 and n != 1 and isprime(n)) or (n == 1 and m != 2):
        print("FastestFinger")
    else:
        print("Ashishgup")
