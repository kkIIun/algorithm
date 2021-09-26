#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, start, End, visited[100001];
vector<ll> path;
vector<vector<pair<ll, ll>>> tree;

ll dfs(ll cur, ll sum)
{
    if (cur == End)
        return sum;
    ll temp;
    for (auto next : tree[cur])
        if (!visited[next.first])
        {
            visited[next.first] = 1;
            path.push_back(next.first);
            temp = dfs(next.first, sum + next.second);
            if (temp)
                return temp;
            path.pop_back();
        }

    return 0;
}

void solve()
{
    ll u, v, w;
    cin >> n;
    tree.assign(n + 1, vector<pair<ll, ll>>());
    for (ll i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        tree[u].push_back(make_pair(v, w));
        tree[v].push_back(make_pair(u, w));
    }
    cin >> m;
    while (m--)
    {
        path.clear();
        memset(visited, 0, sizeof(visited));
        cin >> n >> start >> End;
        visited[start] = 1;
        path.push_back(start);
        if (n == 1)
            cout << dfs(start, 0) << '\n';
        if (n == 2)
        {
            dfs(start, 0);
            cin >> w;
            cout << path[w - 1] << '\n';
        }
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
