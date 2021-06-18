t = int(input())

for _ in range(t):
    n = input()
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]

    o = 0
    z = 0
    for i in range(len(a)):
        if b[i]:
            o += 1
        else:
            z += 1

    Ca = a[:]
    Ca.sort()
    if a == Ca or (o > 0 and z > 0):
        print("YES")
    else:
        print("NO")