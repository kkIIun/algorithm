#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, dp[31];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll TC;
    cin >> TC;
    dp[1] = 1;
    for (ll i = 2; i <= 30; i++)
        dp[i] = (dp[i - 1] + 0.5) * 2;
    while (TC--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
