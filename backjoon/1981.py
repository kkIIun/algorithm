import sys
from collections import deque

input = sys.stdin.readline

move = [[0, 1], [1, 0], [0, -1], [-1, 0]]


def bfs():
    if v[left] > arr[0][0] or v[right] < arr[0][0]:
        return False

    visited = [[False for _ in range(n)] for _ in range(n)]
    visited[0][0] = True

    q = deque()
    q.append((0, 0))

    while q:
        y, x = q.popleft()

        if y == n - 1 and x == n - 1:
            return True

        for i in range(4):
            ny, nx = y + move[i][0], x + move[i][1]

            if (
                ny < 0
                or ny >= n
                or nx < 0
                or nx >= n
                or visited[ny][nx]
                or v[left] > arr[ny][nx]
                or v[right] < arr[ny][nx]
            ):
                continue

            q.append((ny, nx))
            visited[ny][nx] = True

    return False


n = int(input())
arr = [[int(x) for x in input().split()] for _ in range(n)]
v = []
for i in range(n):
    for j in range(n):
        v.append(arr[i][j])
v = list(set(v))
v.sort()

ans = sys.maxsize
left, right = 0, 0
while left <= right and right < len(v):
    if bfs():
        ans = min(ans, v[right] - v[left])
        left += 1
    else:
        right += 1
print(ans)
