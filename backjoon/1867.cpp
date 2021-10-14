#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> graph[501];
ll visited[501], b[501], n, k;

ll dfs(ll cur)
{
    if (visited[cur])
        return 0;
    visited[cur] = 1;

    for (auto next : graph[cur])
        if (!b[next] || dfs(b[next]))
        {
            b[next] = cur;
            return 1;
        }
    return 0;
}

ll bmatch()
{
    ll ret = 0;
    for (ll i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            ret++;
    }
    return ret;
}

void solve()
{
    cin >> n >> k;

    ll row, col;
    for (ll i = 1; i <= k; i++)
    {
        cin >> row >> col;
        graph[row].push_back(col);
    }

    cout << bmatch() << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
