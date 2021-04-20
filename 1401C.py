def GCD(i, j):
    if i < j:
        i, j = j, i
    if j == 0:
        return i
    return GCD(j, i % j)


def solve(arr, Sarr):
    for i in range(len(arr)):
        if (
            arr[i] != Sarr[i]
            and GCD(arr[i], Sarr[i]) != Sarr[0]
            and GCD(arr[i], Sarr[i]) % Sarr[0] != 0
        ):

            return print("NO")

    return print("YES")


t = int(input())

for _ in range(t):
    n = input()
    arr = [int(x) for x in input().split()]
    Sarr = arr[:]
    Sarr.sort()
    solve(arr, Sarr)
