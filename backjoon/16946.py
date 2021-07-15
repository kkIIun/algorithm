import sys
from collections import deque

INF = sys.maxsize

move = [(0, 1), (1, 0), (0, -1), (-1, 0)]


r, c = map(int, sys.stdin.readline().split())
Map = [list(map(int, sys.stdin.readline().strip())) for _ in range(r)]
arr = []
block = []
arr.append(0)
visited = [[0 for _ in range(c)] for _ in range(r)]


def check(ny, nx):
    return ny < 0 or nx < 0 or ny >= r or nx >= c or Map[ny][nx] != 0


def dfs(y, x, num):
    q = []
    visited[y][x] = num
    q.append((y, x))
    cnt = 1
    while q:
        y, x = q.pop()

        for i in range(4):
            ny, nx = y + move[i][0], x + move[i][1]
            if check(ny, nx) or visited[ny][nx]:
                continue
            cnt += 1
            q.append((ny, nx))
            visited[ny][nx] = num

    arr.append(cnt)


def countMoves(y, x):
    overlap = []
    for i in range(4):
        ny, nx = y + move[i][0], x + move[i][1]
        if check(ny, nx):
            continue
        overlap.append(visited[ny][nx])

    overlap = set(overlap)
    ans = 0
    for i in overlap:
        ans += arr[i]
    return ans


num = 1
for i in range(r):
    for j in range(c):
        if Map[i][j] or visited[i][j]:
            continue
        dfs(i, j, num)
        num += 1

for i in range(r):
    for j in range(c):
        if Map[i][j]:
            Map[i][j] = (countMoves(i, j) + 1) % 10

for i in range(r):
    print("".join(map(str, Map[i])))
