n, t = map(int, input().split())
a = [int(x) for x in input().split()]

right, left, books, sum = 0, 0, 0, 0
while left != n:
    sum += a[left]

    if sum <= t and books < left + 1 - right:
        books = left + 1 - right

    elif sum > t:
        sum -= a[right]
        right += 1

    left += 1

print(books)