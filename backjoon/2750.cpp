#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;
vector<ll> v;

void solve()
{
    cin >> n;
    v.assign(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    for (ll i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}