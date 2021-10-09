#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[5001], n;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[3] = 1;
    dp[5] = 1;
    for (ll i = 6; i <= n; i++)
    {
        if (dp[i - 3] != -1 && dp[i - 5] != -1)
        {
            dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
            continue;
        }
        else if (dp[i - 3] != -1)
        {
            dp[i] = dp[i - 3] + 1;
            continue;
        }
        else if (dp[i - 5] != -1)
        {
            dp[i] = dp[i - 5] + 1;
            continue;
        }
    }
    cout << dp[n] << '\n';

    return 0;
}
