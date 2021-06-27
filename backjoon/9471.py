p = int(input())

for _ in range(p):
    n, m = map(int, input().split())
    m1, m2 = 1, 1
    count = 1
    while m1 != 0 or m2 != 1:
        count += 1
        m1, m2 = m2, (m1 + m2) % m
    print("{0} {1}".format(n, count))
