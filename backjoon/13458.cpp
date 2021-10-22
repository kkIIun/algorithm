#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ll n, b, c, ans = 0;
    cin >> n;
    vector<ll> v(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    cin >> b >> c;
    for (ll n : v)
    {
        n -= b;
        ans++;
        if (n > 0)
            ans += ceil(n / (c * 1.0));
    }
    cout << ans << '\n';
    return 0;
}