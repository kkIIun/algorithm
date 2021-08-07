import sys
from collections import deque

T = int(input())
for t in range(T):
    a, b, c = sys.stdin.readline().rstrip().split()
    sizeA = len(a)
    sizeB = len(b)
    sizeC = sizeA + sizeB
    ans = "no"
    visited = [[0 for j in range(sizeB + 1)] for i in range(sizeA + 1)]
    q = deque([["", -1, -1, 0]])
    visited[0][0] = 1
    while q:
        nowWord, aIndx, bIndx, size = q.popleft()
        if size == sizeC:
            ans = "yes"
            break
        if aIndx + 1 < sizeA and c[size] == a[aIndx + 1] and visited[aIndx + 2][bIndx + 1] == 0:
            q.append([nowWord + a[aIndx], aIndx + 1, bIndx, size + 1])
            visited[aIndx + 2][bIndx + 1] = 1
        if bIndx + 1 < sizeB and c[size] == b[bIndx + 1] and visited[aIndx + 1][bIndx + 2] == 0:
            q.append([nowWord + b[bIndx], aIndx, bIndx + 1, size + 1])
            visited[aIndx + 1][bIndx + 2] = 1
    print("Data set %d: %s" % (t + 1, ans))
