from collections import deque

move = [[0, 1], [1, 0], [0, -1], [-1, 0]]


def bfs(x, y):
    q = deque()
    c = [[-1 for _ in range(w + 2)] for _ in range(h + 2)]
    q.append([y, x])
    c[y][x] = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + move[i][0], x + move[i][1]
            if ny < 0 or ny >= h + 2 or nx < 0 or nx >= w + 2 or c[ny][nx] != -1:
                continue

            if Map[ny][nx] == ".":
                q.appendleft([ny, nx])
                c[ny][nx] = c[y][x]

            elif Map[ny][nx] == "#":
                q.append([ny, nx])
                c[ny][nx] = c[y][x] + 1
    return c


def insert_map():
    m = [["." for _ in range(w + 2)]]
    for _ in range(h):
        m.append(list("." + input() + "."))
    m.append(["." for _ in range(w + 2)])
    return m


def get_start():
    location = []
    for i in range(h + 2):
        for j in range(w + 2):
            if Map[i][j] == "$":
                Map[i][j] = "."
                location.append([i, j])
    return location


T = int(input())

for _ in range(T):
    h, w = map(int, input().split())
    Map = insert_map()
    location = get_start()
    c = bfs(0, 0)
    c1 = bfs(location[0][1], location[0][0])
    c2 = bfs(location[1][1], location[1][0])

    Min = 1000000
    ans = Min
    for i in range(h + 2):
        for j in range(w + 2):
            if c[i][j] != -1 and c1[i][j] != -1 and c2[i][j] != -1:
                Min = c[i][j] + c1[i][j] + c2[i][j]
                if Map[i][j] == "#":
                    Min -= 2
                ans = min(ans, Min)
    print(ans)
