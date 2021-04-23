import math

mod = int(math.pow(10, 9)) + 7

f = [int(x) for x in input().split()]
f.append(f[1] - f[0])

n = int(input()) - 1

if (n // 3) % 2 != 0:
    print(-f[n % 3] % mod)

else:
    print(f[n % 3] % mod)