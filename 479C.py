n = int(input())

day = 0
a = []
b = []
for _ in range(n):
    inp = [int(x) for x in input().split()]
    a.append(inp[0])
    b.append(inp[1])

for i in range(len(a)):
    for j in range(i, len(a)):
        if a[i] > a[j]:
            a[i], a[j] = a[j], a[i]
            b[i], b[j] = b[j], b[i]

        elif a[i] == a[j] and b[i] > b[j]:
            a[i], a[j] = a[j], a[i]
            b[i], b[j] = b[j], b[i]

for i in range(len(a)):
    if day > b[i]:
        day = a[i]
    else:
        day = b[i]

print(day)
