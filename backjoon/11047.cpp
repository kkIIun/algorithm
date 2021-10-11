#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> v(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    n--;
    while (m)
    {
        if (m >= v[n])
        {
            ans += m / v[n];
            m %= v[n];
        }
        n--;
    }
    cout << ans << '\n';

    return 0;
}
