import sys
from collections import deque

input = sys.stdin.readline
INF = sys.maxsize

move = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def Range(ny, nx):
    return ny < 0 or nx < 0 or ny >= n or nx >= n or House[ny][nx] == "*"


def bfs():
    y, x = door[0]
    q = deque()
    visited = [[[INF for _ in range(4)] for _ in range(n)] for _ in range(n)]

    for i in range(4):
        ny, nx = y + move[i][0], x + move[i][1]
        if Range(ny, nx):
            continue
        q.append((y, x, i, 0))
        visited[y][x][i] = 0

    while q:
        y, x, Dir, mir = q.popleft()
        ny, nx = y + move[Dir][0], x + move[Dir][1]
        if Range(ny, nx) or visited[ny][nx][Dir] < mir:
            continue

        if House[ny][nx] == "!":
            d1 = (Dir + 1) % 4
            d2 = (Dir + 3) % 4

            if visited[ny][nx][d1] > mir + 1:
                q.append((ny, nx, d1, mir + 1))
                visited[ny][nx][d1] = mir + 1

            if visited[ny][nx][d2] > mir + 1:
                q.append((ny, nx, d2, mir + 1))
                visited[ny][nx][d2] = mir + 1

        q.append((ny, nx, Dir, mir))
        visited[ny][nx][Dir] = mir

    return min(visited[door[1][0]][door[1][1]])


n = int(input())
House = [[] for _ in range(n)]
door = []

for i in range(n):
    Row = list(input())
    for j in range(n):
        House[i].append(Row[j])
        if Row[j] == "#":
            door.append((i, j))

print(bfs())
