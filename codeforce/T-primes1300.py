n = int(input())
T = [int(x) for x in input().split()]
limit = int(pow(1000000000000, 0.5)) + 1
prime = [False] * 2 + [True] * (limit - 2)

for i in range(2, limit):
    if prime[i]:
        for j in range(i * 2, limit, i):
            prime[j] = False

for num in T:
    sqrt = int(pow(num, 0.5))
    print("YES" if sqrt ** 2 == num and prime[sqrt] else "NO")
