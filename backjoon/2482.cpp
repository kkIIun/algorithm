#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll;
ll n, k;
ll dp[1002][1002];
ll DIV = 1000000003;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (ll i = 0; i <= n; i++)
        dp[i][0] = 1;
    dp[1][1] = 1;
    for (ll i = 2; i <= n; i++)
        for (ll j = 1; 2 * j <= i + 1; j++)
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % DIV;
    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % DIV;

    return 0;
}
