import sys
from collections import deque

input = sys.stdin.readline
INF = sys.maxsize

q = []
nq = []
n, k = map(int, input().split())
q.append(n)
over = {}

ans = -1
check = True
while check:
    while q:
        num = q.pop()
        if num in over:
            continue
        over[num] = 1
        if num == k:
            check = False
            break
        if num > 0:
            nq.append(num - 1)
        if num < k:
            nq.append(num + 1)
            nq.append(num * 2)
    q = list(set(nq))
    nq = []
    ans += 1

print(ans)
