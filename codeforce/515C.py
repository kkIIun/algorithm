import math


def primeNum(num):
    for i in range(2, int(math.pow(num, 0.5)) + 1):
        if num % i == 0:
            return False
    return True


n = int(input())
a = list(map(int, input()))

ans = []
for i in range(len(a)):
    if a[i] == 0 or a[i] == 1:
        pass

    elif primeNum(a[i]):
        ans.append(a[i])

    else:
        num = 1
        while not primeNum(a[i]):
            num *= a[i]
            a[i] -= 1
        ans.append(a[i])

        while num % 6 == 0:
            ans.append(3)
            num //= 6

        while num % 2 == 0:
            ans.append(2)
            num //= 2

ans.sort(reverse=True)
print("".join(map(str, ans)))
