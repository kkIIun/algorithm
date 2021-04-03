def freinds_pair(num):
    return int(num * (num - 1) / 2)


n, m = map(int, input().split())

a, b = n // m, n % m
Max, Min = freinds_pair(n - m + 1), freinds_pair(a) * (m - b) + freinds_pair(a + 1) * (b)
if Max > pow(10, 9):
    Max = round(Max, -3)
print(Min, Max)
