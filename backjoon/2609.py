def GCF(a, b):
    if a == b:
        return a
    if a == 1 or b == 1:
        return 1

    if b > a:
        return GCF(b - a, a)

    return GCF(a - b, b)


n1, n2 = map(int, input().split())
gcf = GCF(n1, n2)
print(gcf)
print(n1 * n2 // gcf)
