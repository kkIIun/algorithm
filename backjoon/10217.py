import heapq, sys

input = sys.stdin.readline
INF = sys.maxsize


def dp():
    dist = [[INF] * (m+ 1) for _ in range(n+1)]
    dist[1][0] = 0
    
    for cost in range(m+1):
        for node in range(1,n+1):
            if dist[node][cost] == INF:
                continue

            for v, c, d in graph[node]:
                if c + cost > m:
                    continue
                dist[v][c+cost] = min(dist[v][c+cost], dist[node][cost] + d)
                
    return min(dist[n])


ans = []
for _ in range(int(input())):
    n, m, k = map(int, input().split())
    graph = [[] for _ in range(n + 1)]

    for _ in range(k):
        u, v, c, d = map(int, input().split())
        graph[u].append((v, c, d))

    ans.append(dp())

for val in ans:
    print(val if val != INF else "Poor KCM")
