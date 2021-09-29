#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, temp;
vector<vector<ll>> v, rev;
vector<ll> visited, SCC, indegree;
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
    SCC[cur] = idx;
    for (auto next : rev[cur])
        if (!visited[next])
            dfs(next, idx);
}

ll count()
{
    ll cnt = 0;
    for (ll i = 0; i < indegree.size(); i++)
        if (!indegree[i])
        {
            cnt++;
            temp = i;
        }

    return cnt;
}

void init()
{
    visited.assign(n, 0);
    SCC.assign(n, 0);
    v.assign(n, vector<ll>());
    rev.assign(n, vector<ll>());
}

void solve()
{
    cin >> n >> m;
    init();

    ll a, b;
    while (m--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        rev[b].push_back(a);
    }

    for (ll i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    visited.assign(n, 0);

    ll t = 0;
    while (!st.empty())
    {
        ll temp = st.top();
        st.pop();
        if (!visited[temp])
            dfs(temp, t++);
    }

    indegree.assign(t, 0);
    for (ll i = 0; i < n; i++)
        for (auto j : v[i])
            if (SCC[i] != SCC[j])
                indegree[SCC[j]]++;

    if (count() == 1)
        for (ll i = 0; i < n; i++)
        {
            if (SCC[i] == temp)
                cout << i << '\n';
        }
    else
        cout << "Confused" << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll TC;
    cin >> TC;
    while (TC--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}