import sys, heapq

INF = sys.maxsize
input = sys.stdin.readline


def dijkstra(start):
    distance = [INF for _ in range(ist + 1)]
    q = []
    heapq.heappush(q, [0, start])
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        for i in road[now]:
            cost = dist + i[1]

            if distance[i[0]] > cost:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

    return distance


for _ in range(int(input())):
    ist, roadC, des = map(int, input().split())
    first, g, h = map(int, input().split())

    road = [[] for _ in range(ist + 1)]
    for _ in range(roadC):
        a, b, d = map(int, input().split())
        road[a].append([b, d])
        road[b].append([a, d])
    S, G, H = dijkstra(first), dijkstra(g), dijkstra(h)

    de = []
    for _ in range(des):
        de.append(int(input()))

    ans = []
    for x in de:
        if S[x] == S[g] + G[h] + H[x] or S[x] == S[h] + H[g] + G[x]:
            ans.append(x)

    ans.sort()
    for f in ans:
        print(f, end=" ")
    print()
