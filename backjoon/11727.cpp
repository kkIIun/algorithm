#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] % 10007 + (dp[i - 2] * 2) % 10007) % 10007;
    }
    cout << dp[n];
    return 0;
}
