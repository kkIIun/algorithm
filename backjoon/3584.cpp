#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, depth[100001];
vector<vector<ll>> v, parent;

void setTree(ll start)
{
    for (auto next : v[start])
    {
        depth[next] = depth[start] + 1;
        setTree(next);
    }
}

void solve()
{
    ll a, b;
    cin >> n;
    v.assign(n + 1, vector<ll>());
    parent.assign(n + 1, vector<ll>());
    for (ll i = 1; i < n; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        parent[b].push_back(a);
    }
    for (ll i = 1; i <= n; i++)
        if (!parent[i].size())
            setTree(i);
    cin >> a >> b;
    while (a != b)
    {
        if (depth[a] <= depth[b])
            swap(a, b);
        a = parent[a][0];
    }
    cout << a << '\n';
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
