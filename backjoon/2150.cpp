#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll v, e, visited[100001], cnt;
vector<vector<ll>> ans, front, back;
stack<ll> st;

bool cmp(vector<ll> a, vector<ll> b)
{
    return a[0] < b[0];
}

void Fdfs(ll cur)
{
    visited[cur] = 1;
    for (auto next : front[cur])
    {
        if (!visited[next])
            Fdfs(next);
    }
    st.push(cur);
}

void Rdfs(ll cur)
{
    visited[cur] = 1;
    ans[cnt - 1].push_back(cur);
    for (auto next : back[cur])
    {
        if (!visited[next])
            Rdfs(next);
    }
}

void solve()
{
    cin >> v >> e;
    front.resize(v + 1);
    back.resize(v + 1);
    ll a, b;
    for (ll i = 0; i < e; i++)
    {
        cin >> a >> b;
        front[a].push_back(b);
        back[b].push_back(a);
    }

    for (ll i = 1; i <= v; i++)
        if (!visited[i])
            Fdfs(i);

    memset(visited, 0, sizeof(visited));
    while (!st.empty())
    {
        ll cur = st.top();
        st.pop();
        if (!visited[cur])
        {
            ans.resize(++cnt);
            Rdfs(cur);
        }
    }
    cout << cnt << '\n';
    for (ll i = 0; i < cnt; i++)
        sort(ans[i].begin(), ans[i].end());
    sort(ans.begin(), ans.end(), cmp);
    for (ll i = 0; i < cnt; i++)
    {
        for (ll j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << -1 << '\n';
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
