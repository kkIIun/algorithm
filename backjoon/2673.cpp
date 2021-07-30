#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, dp[101][101], cost[101][101];

void Solve()
{
    for (ll i = 1; i <= 100; ++i)
        for (ll j = i; j >= 1; --j)
            for (ll k = j; k < i; k++)
                dp[j][i] = max(dp[j][i], dp[j][k] + dp[k][i] + cost[j][i]);
    cout << dp[1][100] << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        cost[a][b] = cost[b][a] = 1;
    }
    Solve();
    return 0;
}
