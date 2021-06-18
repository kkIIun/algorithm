n, k = map(int, input().split())
P = [[0 for x in range(k+1)] for x in range(n+1)]
w, v = [], []

for i in range(n):
    a, b = map(int, input().split())
    w.append(a)
    v.append(b)

for i in range(1,n+1) :
    for j in range(1, k+1):
        if j < w[i-1] :
            P[i][j] = P[i-1][j]
        else :
            P[i][j] = max(P[i-1][j], v[i-1] + P[i-1][j-w[i-1]])

print(P[n][k])
