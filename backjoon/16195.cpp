#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, dp[1001][1001];
const ll DIV = 1000000009;

void Solve()
{
    dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = 1;
    for (ll i = 3; i <= 1000; i++)
        for (ll j = 2; j <= 1000; j++)
            dp[i][j] = (dp[i - 1][j - 1] % DIV + dp[i - 2][j - 1] % DIV + dp[i - 3][j - 1] % DIV) % DIV;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        for (ll i = 1; i <= b; i++)
            ans += dp[a][i];
        cout << ans % DIV << endl;
    }
    return 0;
}
