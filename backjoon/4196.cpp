#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, visited[100001], ans;
vector<vector<ll>> v;
stack<ll> stk;

void dfs(ll cur)
{
    for (auto next : v[cur])
        if (!visited[next])
        {
            visited[next] = 1;
            dfs(next);
        }
    stk.push(cur);
}

void dfs2(ll cur)
{
    for (auto next : v[cur])
        if (!visited[next])
        {
            visited[next] = 1;
            dfs2(next);
        }
}

void solve()
{
    cin >> n >> m;
    v.assign(n + 1, vector<ll>());
    memset(visited, 0, sizeof(visited));

    ll x, y;
    while (m--)
    {
        cin >> x >> y;
        v[x].push_back(y);
    }

    for (ll i = 1; i <= n; i++)
        if (!visited[i])
        {
            visited[i] = 1;
            dfs(i);
        }

    memset(visited, 0, sizeof(visited));
    ans = 0;
    while (!stk.empty())
    {
        ll temp = stk.top();
        stk.pop();
        if (!visited[temp])
        {
            visited[temp] = 1;
            dfs2(temp);
            ans++;
        }
    }
    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll TC;
    cin >> TC;
    while (TC--)
        solve();
    return 0;
}
