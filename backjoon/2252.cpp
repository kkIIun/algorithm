#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> graph;
ll *visited;

void dfs(ll cur)
{
    for (auto next : graph[cur])
        if (!visited[next])
        {
            visited[next] = 1;
            dfs(next);
        }
    cout << cur << ' ';
}

void solve()
{
    ll n, m, *root;
    cin >> n >> m;
    root = new ll[n + 1];
    visited = new ll[n + 1];
    graph.assign(n + 1, vector<ll>());

    ll a, b;
    while (m--)
    {
        cin >> a >> b;
        graph[b].push_back(a);
        root[a] = 1;
    }

    for (ll i = 1; i <= n; i++)
        if (!root[i])
        {
            visited[i] = 1;
            dfs(i);
        }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}