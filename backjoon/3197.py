from collections import deque
def melt():
    size = len(water)
    for _ in range(size):
        y,x = water.popleft() 
        for i in range(4):
            next_x = x + move[i][0]
            next_y = y + move[i][1]

            if next_x < 0 or next_y < 0 or next_x >= Col or next_y >= Row:
                continue
            if lake[next_y][next_x] == "X":
                lake[next_y][next_x] = "."
                water.append([next_y, next_x])


def bfs():
    day = 0
    next_q = deque()
    next_q.append([swan[0][0], swan[0][1]])
    q = deque()
    visited = [[0 for _ in range(Col)] for _ in range(Row)]
    visited[next_q[0][0]][next_q[0][1]] = 1
    while 1:
        q = next_q
        next_q = deque()
        while q:
            y, x =q.popleft()
            if y == swan[1][0] and x == swan[1][1]:
                return day

            for i in range(4):
                next_x = x + move[i][0]
                next_y = y + move[i][1]

                if next_x < 0 or next_y < 0 or next_x >= Col or next_y >= Row or visited[next_y][next_x]:
                    continue

                visited[next_y][next_x] = 1 

                if lake[next_y][next_x] == "X":
                    next_q.append([next_y,next_x])
                    continue
                    
                q.append([next_y, next_x])
        melt()
        day += 1


Row, Col = map(int, input().split())
water = deque()
swan = []
lake = []
move = [[1, 0], [0, 1], [-1, 0], [0, -1]]

for i in range(Row):
    lake.append(list(input()))
    for j in range(Col):
        if lake[i][j] == ".":
            water.append([i, j])
        elif lake[i][j] == "L":
            water.append([i, j])
            swan.append([i, j])

print(bfs())
