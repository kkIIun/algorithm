import math


def isprime(n):
    for i in range(2, int(math.pow(n, 0.5)) + 1):
        if n % i == 0:
            return False
    return True


t = int(input())

for _ in range(t):
    ans = 1  # odd FastestFinger, even Ashishgup win
    n = int(input())
    while n != 1:
        if n % 2 != 0:
            n //= n
        else:
            copy = n
            div = n
            while div % 2 == 0:
                div //= 2
            while not isprime(div):
                if n // div > 2:
                    n //= div
                    break
                else:
                    for i in range(3, div + 1):
                        if div % i == 0:
                            div //= i
                            break
            if n == copy:
                n -= 1
        ans += 1
    if ans % 2 == 0:
        print("Ashishgup")
    else:
        print("FastestFinger")
