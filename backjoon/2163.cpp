#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[301], m, n;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 2; i <= m; i++)
        dp[i] = dp[i - 1] + 1;
    cout << dp[m] * n + (n - 1) << '\n';

    return 0;
}
