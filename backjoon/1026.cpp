#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, ans;

bool cmp(ll a, ll b)
{
    return a > b;
}

void solve()
{
    vector<ll> a, b;
    a.assign(n, 0);
    b.assign(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);
    for (ll i = 0; i < n; i++)
        ans += a[i] * b[i];
    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    solve();
    return 0;
}
