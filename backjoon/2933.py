from collections import deque


def Destroy(h, i):
    if i % 2:
        for j in range(C - 1, -1, -1):
            if cave[R - h][j] == "x":
                cave[R - h][j] = "."
                return

    else:
        for j in range(C):
            if cave[R - h][j] == "x":
                cave[R - h][j] = "."
                return


def BFS_Cluster():
    for i in range(R):
        for j in range(C):
            visited[i][j] = 0
    q = deque()

    for i in range(C):
        if cave[R - 1][i] == "x":
            q.append([R - 1, i])
            visited[R - 1][i] = 1

    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + move[i][0], x + move[i][1]
            if ny < 0 or ny >= R or nx < 0 or nx >= C or visited[ny][nx]:
                continue

            if cave[ny][nx] == "x":
                visited[ny][nx] = 1
                q.append([ny, nx])


def Down():
    minH = 100
    H = 0
    for i in range(R):
        for j in range(C):
            if visited[i][j] == 0 and cave[i][j] == "x":
                for n in range(i + 1, R):
                    if visited[n][j] == 1:
                        break
                    H += 1

                if minH > H:
                    minH = H
                H = 0

    for i in range(R - 1, -1, -1):
        for j in range(C - 1, -1, -1):
            if visited[i][j] == 0 and cave[i][j] == "x":
                cave[i][j], cave[i + minH][j] = ".", "x"


R, C = map(int, input().split())
visited = [[0 for _ in range(C)] for _ in range(R)]
move = [[0, 1], [1, 0], [0, -1], [-1, 0]]
cave = [list(input()) for _ in range(R)]

N = int(input())
h = [int(x) for x in input().split()]
ans = ""
for i in range(N):
    Destroy(h[i], i)
    BFS_Cluster()
    Down()

for i in range(R):
    for j in range(C):
        ans += cave[i][j]
    print(ans)
    ans = ""