mod = 1500000
pibo = [None] * mod
pibo[0] = 1
pibo[1] = 1
for i in range(2, len(pibo)):
    pibo[i] = (pibo[i - 1] + pibo[i - 2]) % 1000000

n = int(input())
print(pibo[(n - 1) % mod])
