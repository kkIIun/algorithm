import math


def query(arr, tree, node, start, end, left, right):
    if end < left or start > right:
        return -1

    if end <= right and start >= left:
        return tree[node]

    mid = (start + end) // 2
    m1 = query(arr, tree, node * 2, start, mid, left, right)
    m2 = query(arr, tree, node * 2 + 1, mid + 1, end, left, right)

    if m1 == -1:
        return m2

    elif m2 == -1:
        return m1

    else:
        if arr[m1] <= arr[m2]:
            return m1
        else:
            return m2


def init(arr, tree, node, start, end):
    if start == end:
        tree[node] = start
    else:
        mid = (start + end) // 2
        init(arr, tree, node * 2, start, mid)
        init(arr, tree, node * 2 + 1, mid + 1, end)

        if arr[tree[node * 2]] > arr[tree[node * 2 + 1]]:
            tree[node] = tree[node * 2 + 1]
        else:
            tree[node] = tree[node * 2]


def getMax(arr, tree, start, end):
    mid = query(arr, tree, 1, 0, len(arr) - 1, start, end)

    area = arr[mid] * (end - start + 1)
    if start <= mid - 1:
        area = max(area, getMax(arr, tree, start, mid - 1))

    if end >= mid + 1:
        area = max(area, getMax(arr, tree, mid + 1, end))

    return area


while 1:
    h = [int(x) for x in input().split()]
    n = h.pop(0)
    if n == 0:
        break
    l = math.ceil(math.log2(n))
    tree = [None] * (1 << l + 1)

    init(h, tree, 1, 0, n - 1)
    print(getMax(h, tree, 0, n - 1))
