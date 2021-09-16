#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ans;
vector<ll> v;

void solve()
{
    v.assign(6, 0);
    for (ll i = 0; i < 6; i++)
        cin >> v[i];
    ll total, temp;
    for (ll i = 5; i >= 0; i--)
    {
        switch (i)
        {
        case 5:
            ans += v[i];
            break;
        case 4:
            ans += v[i];
            v[0] -= v[i] * 11;
            break;
        case 3:
            ans += v[i];
            v[1] -= v[i] * 5;
            break;
        case 2:
            if (!v[i])
                break;
            ans += ceil(v[i] / 4.0);
            v[i] %= 4;
            if (!v[i])
                break;
            v[1] -= 7 - v[i] * 2;
            v[0] -= 8 - v[i];
            break;
        case 1:
            if (v[i] > 0)
            {
                ans += ceil(v[i] / 9.0);
                v[i] %= 9;
                if (!v[i])
                    break;
                v[0] -= 36 - v[i] * 4;
            }
            else
                v[0] += v[i] * 4;
            break;
        case 0:
            if (v[i] <= 0)
                break;
            ans += ceil(v[i] / 36.0);
            break;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    cout << ans << '\n';
    return 0;
}