#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits>
using namespace std;

typedef long long ll;
ll Max = 1000 * 1000 + 1;
ll dp[1000][3] = {};
ll cost[1000][3] = {};
ll N;
ll ans = Max;
ll startC;

ll dfs(ll current, ll color)
{
    if (current == N - 1)
    {
        if (color == startC)
            return Max;
        return cost[current][color];
    }

    if (dp[current][color] != -1)
        return dp[current][color];

    dp[current][color] = Max;
    for (ll i = 0; i < 3; i++)
        if (i != color)
            dp[current][color] = min(dp[current][color], dfs(current + 1, i));

    dp[current][color] += cost[current][color];
    return dp[current][color];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (ll i = 0; i < N; i++)
        for (ll j = 0; j < 3; j++)
            cin >> cost[i][j];

    for (ll i = 0; i < 3; i++)
    {
        memset(dp, -1, sizeof(dp));
        startC = i;
        ans = min(ans, dfs(0, i));
    }

    cout << ans << '\n';
    return 0;
}
