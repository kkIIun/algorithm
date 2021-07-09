import sys
from collections import deque

input = sys.stdin.readline
move = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def findSE():
    for i in range(r):
        for j in range(c):
            if Map[i][j] == "M":
                start.append((i, j))
                Map[i][j] = "."

            if Map[i][j] == "Z":
                end.append((i, j))
                Map[i][j] = "."


def append(x, y, Dir, q):
    ny, nx = y + move[Dir][0], x + move[Dir][1]
    q.append((ny, nx, Dir))


def dfs():
    q = []

    y, x = start[0]
    for i in range(4):
        ny, nx = y + move[i][0], x + move[i][1]

        if ny < 0 or nx < 0 or ny >= r or nx >= c or Map[ny][nx] == ".":
            continue

        if Map[ny][nx] == "|" and (i == 4 or i == 2):
            continue

        elif Map[ny][nx] == "-" and (i == 3 or i == 1):

            continue

        elif Map[ny][nx] == "1" and (i == 0 or i == 1):

            continue

        elif Map[ny][nx] == "2" and (i == 0 or i == 3):

            continue

        elif Map[ny][nx] == "3" and (i == 3 or i == 2):

            continue

        elif Map[ny][nx] == "4" and (i == 2 or i == 1):

            continue

        q.append((ny, nx, i))
        break

    while q:
        y, x, Dir = q.pop()

        if Map[y][x] == "|":
            append(x, y, Dir, q)

        elif Map[y][x] == "-":
            append(x, y, Dir, q)

        elif Map[y][x] == "+":
            append(x, y, Dir, q)

        elif Map[y][x] == "1":
            if Dir == 2:
                Dir = 1

            if Dir == 3:
                Dir = 0

            append(x, y, Dir, q)

        elif Map[y][x] == "2":
            if Dir == 2:
                Dir = 3

            if Dir == 1:
                Dir = 0

            append(x, y, Dir, q)

        elif Map[y][x] == "3":
            if Dir == 1:
                Dir = 2

            if Dir == 0:
                Dir = 3

            append(x, y, Dir, q)

        elif Map[y][x] == "4":
            if Dir == 0:
                Dir = 1

            if Dir == 3:
                Dir = 2

            append(x, y, Dir, q)

        else:
            return (y, x)


r, c = map(int, input().split())
Map = [list(input()) for _ in range(r)]
start = []
end = []
findSE()
y, x = dfs()
stack = []
for i in range(4):
    ny, nx = y + move[i][0], x + move[i][1]

    if ny < 0 or nx < 0 or ny >= r or nx >= c or Map[ny][nx] == ".":
        continue

    if Map[ny][nx] == "|" and (i == 0 or i == 2):
        continue

    elif Map[ny][nx] == "-" and (i == 3 or i == 1):

        continue

    elif Map[ny][nx] == "1" and (i == 0 or i == 1):

        continue

    elif Map[ny][nx] == "2" and (i == 0 or i == 3):

        continue

    elif Map[ny][nx] == "3" and (i == 3 or i == 2):

        continue

    elif Map[ny][nx] == "4" and (i == 2 or i == 1):

        continue

    stack.append(i)
x += 1
y += 1

if [1, 3] == stack:
    print(y, x, "|")

elif [0, 2] == stack:
    print(y, x, "-")

elif [0, 1] == stack:
    print(y, x, "1")

elif [0, 3] == stack:
    print(y, x, "2")

elif [2, 3] == stack:
    print(y, x, "3")

elif [1, 2] == stack:
    print(y, x, "4")

else:
    print(y, x, "+")
