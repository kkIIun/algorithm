#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k, visited[1001], b[1001];
vector<vector<ll>> Map;

bool dfs(ll cur)
{
    if (visited[cur])
        return false;
    visited[cur] = 1;

    for (auto next : Map[cur])
        if (!b[next] || dfs(b[next]))
        {
            b[next] = cur;
            return true;
        }

    return false;
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

    for (ll i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        while (dfs(i) && k > 0)
        {
            memset(visited, 0, sizeof(visited));
            ret++;
            k--;
        }
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    Map.assign(n + 1, vector<ll>());

    ll a, b;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a;
        while (a--)
        {
            cin >> b;
            Map[i].push_back(b);
        }
    }
    cout << bmatch() << '\n';
    return 0;
}
