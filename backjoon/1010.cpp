#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[30][30];

ll comb(ll n, ll m)
{
    if (m == 0 || n == m)
        return 1;

    if (dp[n][m])
        return dp[n][m];

    dp[n][m] = comb(n - 1, m) + comb(n - 1, m - 1);
    dp[n][n - m] = comb(n - 1, m) + comb(n - 1, m - 1);
    return dp[n][m];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll test;
    cin >> test;
    while (test--)
    {
        ll n, m;
        cin >> n >> m;
        cout << comb(m, n) << '\n';
    }
    return 0;
}
