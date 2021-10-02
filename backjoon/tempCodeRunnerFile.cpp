#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, sccNum = 0;
vector<vector<ll>> v, rev;
stack<ll> st;
ll SCC[20001], visited[20001];

ll tra(ll n)
{
    if (n > 0)
        return n;
    return -n + 10000;
}

void dfs(ll cur)
{
    visited[cur] = 1;
    for (auto next : v[cur])
        if (!visited[next])
            dfs(next);
    st.push(cur);
}

void dfs(ll cur, ll sccNum)
{
    visited[cur] = 1;
    SCC[cur] = sccNum;
    for (auto next : rev[cur])
        if (!visited[next])
            dfs(next, sccNum);
}

bool bfs(ll start)
{
    queue<ll> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();

        if (visited[cur] && visited[cur + 10000])
            return false;

        for (auto next : v[cur])
            if (!visited[next])
            {
                visited[next] = 1;
                q.push(next);
            }
    }
    return true;
}

void solve()
{
    cin >> n >> m;
    v.assign(20001, vector<ll>());
    rev.assign(20001, vector<ll>());
    ll x, y;
    while (m--)
    {
        cin >> x >> y;
        v[tra(-x)].push_back(tra(y));
        rev[tra(y)].push_back(tra(-x));
        v[tra(-y)].push_back(tra(x));
        rev[tra(x)].push_back(tra(-y));
    }

    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
        if (!visited[i + 10000])
            dfs(i + 10000);
    }

    memset(visited, 0, sizeof(visited));

    while (!st.empty())
    {
        ll cur = st.top();
        st.pop();
        if (!visited[cur])
            dfs(cur, ++sccNum);
    }

    for (ll i = 1; i <= n; i++)
        if (SCC[i] == SCC[i + 10000])
        {
            cout << 0;
            return;
        }
    cout << 1 << '\n';
    memset(visited, 0, sizeof(visited));
    if (bfs(1))
    {
        for (ll i = 1; i <= n; i++)
        {
            if (visited[i])
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        break;
    }

    else
    {
        memset(visited, 0, sizeof(visited));
        bfs(10001);
        for (ll i = 1; i <= n; i++)
        {
            if (visited[i])
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
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