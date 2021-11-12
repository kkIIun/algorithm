#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

int main(void)
{
    ll test, dp[101][101], d[101];
    cin >> test;
    while (test--)
    {
        memset(dp, 0, sizeof(dp));
        memset(d, 0, sizeof(d));
        ll n;
        cin >> n;
        for (ll i = 0; i <= n; i++)
            cin >> d[i];
        for (ll i = 1; i < n; i++)
            for (ll j = 1; j + i <= n; j++)
                for (ll k = j; k < j + i; k++)
                {
                    if (!dp[j][j + i])
                        dp[j][j + i] = dp[j][k] + dp[k + 1][i + j] + d[j - 1] * d[k] * d[i + j];

                    else
                        dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][i + j] + d[j - 1] * d[k] * d[i + j]);
                }
        cout << dp[1][n] << '\n';
    }
    return 0;
}