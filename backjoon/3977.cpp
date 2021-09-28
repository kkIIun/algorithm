#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, temp;
vector<vector<ll>> v, rev;
vector<ll> visited, SCC, indegree;
stack<ll> st;

void dfs1(ll cur)
{
    for (auto next : v[cur])
        if (!visited[next])
        {
            visited[next] = 1;
            dfs1(next);
        }
    st.push(cur);
}

void dfs2(ll cur, ll idx)
{
    SCC[cur] = idx;
    for (auto next : rev[cur])
        if (!visited[next])
        {
            visited[next] = 1;
            dfs2(next, idx);
        }
}

void bfs()
{
    queue<ll> q;
    for (ll i = 0; i < indegree.size(); i++)
        if (!indegree[i])
        {
            for (ll j = 0; j < n; j++)
                if (SCC[j] == i)
                {
                    q.push(j);
                    visited[j] = 1;
                    break;
                }
            temp = i;
            break;
        }

    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        for (auto next : v[cur])
            if (!visited[next])
            {
                visited[next] = 1;
                q.push(next);
            }
    }
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
        {
            visited[i] = 1;
            dfs1(i);
        }

    visited.assign(n, 0);

    ll t = 0;
    while (!st.empty())
    {
        ll temp = st.top();
        st.pop();
        if (!visited[temp])
        {
            visited[temp] = 1;
            dfs2(temp, t);
            t++;
        }
    }

    indegree.assign(t, 0);
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < v[i].size(); j++)
            if (SCC[i] != SCC[v[i][j]])
                indegree[SCC[v[i][j]]]++;

    visited.assign(n, 0);
    bfs();
    for (ll i = 0; i < n; i++)
        if (!visited[i])
        {
            cout << "Confused" << '\n';
            return;
        }

    for (ll i = 0; i < n; i++)
        if (SCC[i] == temp)
            cout << i << '\n';
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