from collections import deque

while 1:
    h = [int(x) for x in input().split()]
    n = h.pop(0)
    if n == 0:
        break

    q = deque()
    answer = 0

    for i in range(n):
        while q and h[q[-1]] > h[i]:
            temp = q.pop()
            if q and answer < h[temp] * (i - q[-1] - 1):
                answer = h[temp] * (i - q[-1] - 1)

            elif not (q) and answer < h[temp] * i:
                answer = h[temp] * i

        q.append(i)
    while q:
        temp = q.pop()
        if q and answer < h[temp] * (n - q[-1] - 1):
            answer = h[temp] * (n - q[-1] - 1)

        elif not (q) and answer < h[temp] * n:
            answer = h[temp] * n
    print(answer, q)