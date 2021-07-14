from collections import deque
import sys

input = sys.stdin.readline
move = [[0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1], [-1, 0], [-1, 1]]
start = (7, 0)
end = (0, 7)


def moveBlock():
    for k in range(len(block)):
        i, j = block.pop()
        Map[i][j] = "."
        if i < 7:
            block.appendleft((i + 1, j))
            Map[i + 1][j] = "#"


def checkBlock(y, x):
    for i, j in block:
        if y == i and j == x:
            return True

    return False


def check(ny, nx):
    return nx < 0 or nx >= 8 or ny < 0 or ny >= 8 or Map[ny][nx] == "#"


def bfs():
    q = deque()
    q.append(start)
    while q:
        lq = len(q)
        for _ in range(lq):
            y, x = q.popleft()

            if checkBlock(y, x):
                continue

            if (y == end[0] and x == end[1]) or not (block):
                return 1

            for i in range(8):
                ny, nx = y + move[i][0], x + move[i][1]

                if check(ny, nx):
                    continue

                q.append((ny, nx))
            q.append((y, x))

        moveBlock()
    return 0


Map = [[[] for _ in range(8)] for _ in range(8)]
block = deque()
for i in range(8):
    In = list(input())
    for j in range(8):
        Map[i][j] = In[j]
        if In[j] == "#":
            block.append((i, j))

print(bfs())
