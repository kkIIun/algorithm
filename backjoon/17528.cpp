#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits>
#include <set>
#include <string>
#include <stdio.h>
using namespace std;

typedef unsigned long long ll;
ll n;
ll dp[255][62555];
ll arr[255][2];
ll INF = 198654321;

void Solve()
{
    ll ans = INF;
    dp[1][arr[1][0]] = 0;
    dp[1][0] = arr[1][1];
    for (ll i = 2; i <= n; i++)
        for (ll j = 0; j < 62555; j++)
            if (dp[i - 1][j] != INF)
            {
                dp[i][j + arr[i][0]] = dp[i - 1][j];
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + arr[i][1]);
            }
    for (ll j = 0; j < 62555; j++)
        ans = min(ans, max(j, dp[n][j]));
    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j < 2; j++)
            cin >> arr[i][j];
    memset(dp, INF, sizeof(dp));
    Solve();
    return 0;
}
