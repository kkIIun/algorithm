#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll v, e, visited[10001], cnt;
vector<vector<ll>> front, back, ans;
stack<ll> st;

bool cmp(vector<ll> a, vector<ll> b)
{
    return (a.front() < b.front());
}

void forwardDfs(ll start)
{
    visited[start] = 1;
    for (ll next : front[start])
        if (!visited[next])
            forwardDfs(next);
    st.push(start);
}

void reverseDfs(ll start)
{
    visited[start] = 1;
    ans[cnt].push_back(start);
    for (ll next : back[start])
        if (!visited[next])
            reverseDfs(next);
}

void solve()
{
    cin >> v >> e;
    front.resize(v + 1);
    back.resize(v + 1);
    ans.resize(v + 1);
    ll a, b;
    for (ll i = 0; i < e; i++)
    {
        cin >> a >> b;
        front[a].push_back(b);
        back[b].push_back(a);
    }
    for (ll i = 1; i <= v; i++)
        if (!visited[i])
            forwardDfs(i);
    memset(visited, 0, sizeof(visited));
    while (!st.empty())
    {
        ll temp = st.top();
        st.pop();
        if (!visited[temp])
        {
            reverseDfs(temp);
            cnt++;
        }
    }

    for (ll i = 0; i < cnt; i++)
        sort(ans[i].begin(), ans[i].end());
    sort(ans.begin(), ans.begin() + cnt);

    cout << cnt << '\n';
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
