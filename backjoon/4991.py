from collections import deque
import sys

move = [[0, 1], [1, 0], [0, -1], [-1, 0]]
Max = sys.maxsize


def init():
    for i in range(h):
        for j in range(w):
            if room[i][j] == "o":
                start.appendleft([i, j])

            elif room[i][j] == "*":
                start.append([i, j])


def conditions(ny, nx, nCnt, visited):
    return ny < 0 or ny >= h or nx < 0 or nx >= w or visited[ny][nx] <= nCnt or room[ny][nx] == "x"


def bfs(start):
    q, visited = deque(), [[Max for _ in range(w)] for _ in range(h)]
    q.append([start[0], start[1], 0])
    visited[start[0]][start[1]] = 0
    while q:
        y, x, cnt = q.pop()
        for i in range(4):
            ny, nx, nCnt = y + move[i][0], x + move[i][1], cnt + 1
            if conditions(ny, nx, nCnt, visited):
                continue
            visited[ny][nx] = nCnt
            q.append([ny, nx, nCnt])

    return visited


def dfs(start, cnt, Sum):
    global ref
    if cnt == l:
        ref = min(ref, Sum)

    for i in range(l):
        if not (selected[i]):
            selected[i] = True
            dfs(i, cnt + 1, Sum + path[start][i])
            selected[i] = False


while 1:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break

    room = [list(input()) for _ in range(h)]
    start = deque()
    init()
    l = len(start)
    path = [[0 for _ in range(l)] for _ in range(l)]
    for i in range(l):
        arr = bfs(start[i])
        for j in range(l):
            y, x = start[j][0], start[j][1]
            path[i][j] = arr[y][x]

    ref = Max
    selected = [False for _ in range(l)]
    selected[0] = True
    dfs(0, 1, 0)
    print(ref if ref != Max else -1)
