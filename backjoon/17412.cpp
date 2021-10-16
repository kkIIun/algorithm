#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 1000000000

ll visited[401], c[401][401], f[401][401], n, m, cnt = 0;
vector<vector<ll>> graph;

ll bfs(ll start, ll end)
{
    ll result = 0;
    while (1)
    {
        queue<ll> q;
        q.push(start);
        memset(visited, 0, sizeof(visited));
        while (!q.empty())
        {
            ll cur = q.front();
            q.pop();
            for (auto next : graph[cur])
                if (c[cur][next] - f[cur][next] > 0 && !visited[next])
                {
                    visited[next] = cur;
                    q.push(next);
                    if (next == end)
                        break;
                }
        }
        if (!visited[end])
            return result;
        ll flow = INF;
        for (ll i = end; i != start; i = visited[i])
            flow = min(flow, c[visited[i]][i] - f[visited[i]][i]);

        for (ll i = end; i != start; i = visited[i])
        {
            f[visited[i]][i] += flow;
            f[i][visited[i]] -= flow;
        }
        result += flow;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    graph.assign(n + 1, vector<ll>());

    ll a, b;
    while (m--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        c[a][b] = 1;
    }

    cout << bfs(1, 2) << '\n';
    return 0;
}
