n = list(map(int, input()))

first = True
tmp = len(n) - 1
for i in range(len(n) - 2, -1, -1):
    if first and n[i] % 2 == 0:
        tmp = i
        first = False

    elif n[i] % 2 == 0 and n[i] < n[-1]:
        tmp = i

n[tmp], n[-1] = n[-1], n[tmp]

if n[-1] % 2 != 0:
    print(-1)
else:
    print("".join(map(str, n)))
