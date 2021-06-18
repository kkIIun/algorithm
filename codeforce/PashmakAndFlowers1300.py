import math

n = int(input())
b = [int(x) for x in input().split()]

b.sort()

left, right = 0, n - 1
Max, Min = 1, 1
if b[0] == b[-1]:
    sum = 0
    for i in range(n - 1, 0, -1):
        sum += i
    print(0, sum)

else:
    while b[right] == b[right - 1] or b[left] == b[left + 1]:
        if b[left] == b[left + 1]:
            Max += 1
            left += 1

        if b[right] == b[right - 1]:
            Min += 1
            right -= 1

    print(b[-1] - b[0], Max * Min)
