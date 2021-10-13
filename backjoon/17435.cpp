#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, dp[200001][20];
vector<ll> v;

void solve()
{
    cin >> n;
    v.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        dp[i][0] = v[i];
    }

    for (ll i = 1; i <= 19; i++)
        for (ll j = 1; j <= n; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];

    cin >> m;
    ll x, y,z;
    while (m--)
    {
        cin >> x >> y;
        while (x != 1)
        {
            ll temp = (ll)log2(x);
            y = dp[y][temp];
            x -= pow(2, temp);
            if (!x)
            {
                cout << y << '\n';
                return;
            }
        }
        cout << dp[y][0] << '\n';
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
