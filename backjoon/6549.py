import math


def minIndex(arr):
    Min = 9999999
    index = 0
    for i in range(len(arr)):
        if arr[i] < Min:
            Min = arr[i]
            index = i
    return index


def segmentTree(arr, tree, node, start, end):
    if not (arr):
        return 0

    if start == end:
        tree[node] = arr.pop()
        return tree[node]

    mid = minIndex(arr)
    tree[node] = arr[mid] * len(arr)

    tree[node] = max(
        segmentTree(arr[:mid], tree, node * 2, start, mid - 1),
        segmentTree(arr[mid + 1 :], tree, node * 2 + 1, mid + 1, end),
        tree[node],
    )
    return tree[node]


while 1:
    h = [int(x) for x in input().split()]
    l = math.ceil(math.log2(h[0]))
    tree = [None] * (1 << (l + 2))
    print(len(tree))
    if h.pop(0) == 0:
        break
    print(segmentTree(h, tree, 1, 0, len(h) - 1))
