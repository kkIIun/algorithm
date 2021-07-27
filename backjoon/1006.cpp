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
ll n, w;
ll dp[10001][3];
ll arr[2][10001];
ll INF = 1000000000;

void Solve()
{
    for (ll i = 2; i <= n; ++i)
    {
        ll up = arr[0][i] + arr[0][i - 1] <= w ? 1 : 2;
        ll down = arr[1][i] + arr[1][i - 1] <= w ? 1 : 2;
        ll ver = arr[0][i] + arr[1][i] <= w ? 1 : 2;

        dp[i][0] = min({dp[i - 1][0] + ver, dp[i - 2][0] + up + down, dp[i - 1][2] + down + 1, dp[i - 1][1] + up + 1});
        dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][2] + down);
        dp[i][2] = min(dp[i - 1][0] + 1, dp[i - 1][1] + up);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> w;
        for (ll i = 0; i < 2; i++)
            for (ll j = 1; j <= n; j++)
                cin >> arr[i][j];
        ll start_up = arr[0][1];
        ll start_down = arr[1][1];

        ll ans = INF;
        // 처음과 끝 위,아래 연결 x
        dp[1][0] = arr[0][1] + arr[1][1] <= w ? 1 : 2;
        dp[1][1] = dp[1][2] = 1;
        Solve();

        ans = min(ans, dp[n][0]);

        // 처음과 끝 아래 연결 o
        if (arr[0][1] + arr[0][n] <= w)
        {

            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            arr[0][1] = INF;
            Solve();

            ans = min(ans, dp[n][1]);
            arr[0][1] = start_up;
        }

        // 처음과 끝 위 연결 o
        if (arr[1][1] + arr[1][n] <= w)
        {

            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            arr[1][1] = INF;
            Solve();

            ans = min(ans, dp[n][2]);
            arr[1][1] = start_down;
        }

        // 처음과 끝 위,아래 연결 o
        if (arr[0][1] + arr[0][n] <= w && arr[1][1] + arr[1][n] <= w)
        {

            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            arr[1][1] = arr[0][1] = INF;
            Solve();

            ans = min(ans, dp[n - 1][0]);
            arr[0][1] = start_up;
            arr[1][1] = start_down;
        }

        // 길이가 1
        if (n == 1)
            ans = arr[0][1] + arr[1][1] <= w ? 1 : 2;

        cout << ans << '\n';
    }
    return 0;
}
