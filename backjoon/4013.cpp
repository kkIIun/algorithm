#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, start, sum, a, b, ans;
vector<vector<ll>> v, rev, adj_scc;
vector<ll> visited, SCC, rest, cost, totalCost, cash;
stack<ll> st;

void dfs(ll cur)
{
    visited[cur] = 1;
    for (auto next : v[cur])
        if (!visited[next])
            dfs(next);
    st.push(cur);
}

void dfs(ll cur, ll idx)
{
    visited[cur] = 1;
    cash[idx] += cost[cur];
    SCC[cur] = idx;
    for (auto next : rev[cur])
        if (!visited[next])
            dfs(next, idx);
        else if (SCC[next] != SCC[cur])
            adj_scc[SCC[next]].push_back(SCC[cur]);
}

void bfs()
{
    queue<ll> q;
    totalCost[SCC[start]] = cash[SCC[start]];
    q.push(SCC[start]);
    ans = 0;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        if (rest[cur])
            ans = ans < totalCost[cur] ? totalCost[cur] : ans;

        for (auto next : adj_scc[cur])
        {
            if (totalCost[next] < cash[next] + totalCost[cur])
            {
                totalCost[next] = cash[next] + totalCost[cur];
                q.push(next);
            }
        }
    }
}

void init()
{
    visited.assign(n + 1, 0);
    SCC.assign(n + 1, 0);
    cost.assign(n + 1, 0);
    rest.assign(n + 1, 0);
    cash.assign(n + 1, 0);
    totalCost.assign(n + 1, 0);
    v.assign(n + 1, vector<ll>());
    adj_scc.assign(n + 1, vector<ll>());
    rev.assign(n + 1, vector<ll>());
}

void input()
{
    while (m--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        rev[b].push_back(a);
    }

    for (ll i = 1; i <= n; i++)
        cin >> cost[i];

    cin >> start >> a;
}

void solve()
{
    cin >> n >> m;
    init();
    input();

    for (ll i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);

    visited.assign(n + 1, 0);

    ll scc_num = 0;
    while (!st.empty())
    {
        ll cur = st.top();
        st.pop();
        if (!visited[cur])
            dfs(cur, ++scc_num);
    }

    for (ll i = 0; i < a; i++)
    {
        cin >> b;
        rest[SCC[b]] = 1;
    }
    bfs();
    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}