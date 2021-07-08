import sys

input = sys.stdin.readline
INF = sys.maxsize


def BellmanFord(start):
    distance[start] = 0

    for i in range(city):
        for u, v, w in graph:
            if distance[u] != INF and distance[v] > distance[u] + w:
                distance[v] = distance[u] + w

                if i == city - 1:
                    return True

    return False


city, bus = map(int, input().split())
graph = []
distance = [INF] * (city + 1)

for _ in range(bus):
    u, v, w = map(int, input().split())
    graph.append((u, v, w))

if BellmanFord(1):
    print(-1)

else:
    for i in range(2, city + 1):
        if distance[i] == INF:
            print(-1)
        else:
            print(distance[i])