from collections import deque
import sys

q = deque()
move = [[0, 1], [1, 0], [0, -1], [-1, 0]]


def find():
    arr = []
    for i in range(h):
        for j in range(w):
            if Map[i][j] == "C":
                arr.append([i, j])
                Map[i][j] = "."
    return arr


def bfs():
    for i in range(4):
        q.append([y1, x1, i, 0])
    visited[y1][x1] = 0

    while q:
        y, x, Dir, cnt = q.popleft()
        for i in range(4):
            ny, nx, ncnt = y + move[i][0], x + move[i][1], cnt

            if ny < 0 or ny >= h or nx < 0 or nx >= w or Map[ny][nx] == "*":
                continue

            if Dir != i:
                ncnt = ncnt + 1
            if visited[ny][nx] >= ncnt:
                visited[ny][nx] = ncnt
                q.append([ny, nx, i, ncnt])


w, h = map(int, input().split())
Map = [list(input()) for _ in range(h)]
visited = [[sys.maxsize for _ in range(w)] for _ in range(h)]

temp = find()
x1, y1, x2, y2 = temp[0][1], temp[0][0], temp[1][1], temp[1][0]
bfs()
print(visited[y2][x2])