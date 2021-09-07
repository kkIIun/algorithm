#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;
vector<ll> v;

void dfs(string ans, ll depth, ll prev)
{
    if (depth == m)
    {
        cout << ans << '\n';
        return;
    }

    for (ll i = 0; i < n; i++)
        if (prev <= v[i])
            dfs(ans + ' ' + to_string(v[i]), depth + 1, v[i]);
}

void solve()
{
    cin >> n >> m;

    ll temp;
    for (ll i = 1; i <= n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    for (ll i = 0; i < n; i++)
        dfs(to_string(v[i]), 1, v[i]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
