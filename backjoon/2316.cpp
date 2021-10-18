#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 1000000000

ll parent[801], c[801][801], f[801][801], n, m;
vector<ll> graph[801];

ll bfs(ll start, ll end)
{
    ll ret = 0;
    while (1)
    {
        queue<ll> q;
        q.push(start);
        memset(parent, -1, sizeof(parent));
        while (!q.empty())
        {
            ll cur = q.front();
            q.pop();
            for (auto next : graph[cur])
                if (c[cur][next] - f[cur][next] > 0 && parent[next] == -1)
                {
                    parent[next] = cur;
                    q.push(next);
                    if (next == end)
                        break;
                }
        }
        if (parent[end] == -1)
            return ret;

        ll flow = INF;
        for (ll i = end; i != start; i = parent[i])
            flow = min(flow, c[parent[i]][i] - f[parent[i]][i]);

        for (ll i = end; i != start; i = parent[i])
        {
            f[parent[i]][i] += flow;
            f[i][parent[i]] -= flow;
        }
        ret += flow;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        graph[i].push_back(n + i);
        graph[i + n].push_back(i);
        c[i][n + i] = 1;
    }
    ll a, b;
    while (m--)
    {
        cin >> a >> b;
        graph[n + a].push_back(b);
        graph[b].push_back(n + a);

        graph[b + n].push_back(a);
        graph[a].push_back(n + b);

        c[n + a][b] = 1;
        c[b + n][a] = 1;
    }
    cout << bfs(1 + n, 2) << '\n';
    return 0;
}
