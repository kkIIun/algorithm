#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, End;
vector<vector<ll>> graph;
vector<ll> indegree;
vector<ll> visited;

void bfs(ll start)
{
    queue<ll> q;
    q.push(start);

    while (!q.empty())
    {
        ll cur = q.front();
        visited[cur] = 1;
        cout << cur << ' ';
        q.pop();
        for (auto next : graph[cur])
            if (--indegree[next] == 0)
                q.push(next);
    }
}

void init()
{
    ll a, b;
    while (k--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
}

void solve()
{
    cin >> n >> k;
    graph.assign(n + 1, vector<ll>());
    indegree.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    init();
    for (ll i = 1; i <= n; i++)
        if (!indegree[i] && graph[i].size())
            bfs(i);
    for (ll i = 1; i <= n; i++)
        if (!visited[i])
            cout << i << ' ';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
