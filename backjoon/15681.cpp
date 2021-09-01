#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, r, q, visited[100001], dp[100001];
vector<ll> graph[100001];

ll dfs(ll start)
{

    dp[start] = 1;

    for (ll next : graph[start])
        if (!visited[next])
        {
            visited[next] = 1;
            dp[start] += dfs(next);
            visited[next] = 0;
        }
    return dp[start];
}

void solve()
{
    cin >> n >> r >> q;
    ll u, v;
    for (ll i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    visited[r] = 1;
    dfs(r);
    while (q--)
    {
        cin >> u;
        cout << dp[u] << '\n';
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
