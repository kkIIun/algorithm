import math

r, x1, y1, x2, y2 = map(int, input().split())

distance = math.pow(math.pow(x2 - x1, 2) + math.pow(y2 - y1, 2), 0.5)

print(math.ceil(distance / (r * 2)))
