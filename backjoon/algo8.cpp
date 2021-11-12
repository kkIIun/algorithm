#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

int main(void)
{
    ll test, dp[101][101];
    string a, b;
    cin >> test;
    while (test--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> a >> b;
        for (ll i = 1; i <= a.length(); i++)
            for (ll j = 1; j <= b.length(); j++)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        cout << dp[a.length()][b.length()] << '\n';
    }
    return 0;
}