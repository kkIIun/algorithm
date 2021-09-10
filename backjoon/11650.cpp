#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<pair<ll, ll>> v;

void solve()
{
    cin >> n;
    ll x, y;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());

    for (ll i = 0; i < n; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
