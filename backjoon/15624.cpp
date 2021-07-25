#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits>
#include <set>
#include <string>
using namespace std;

typedef long long ll;
int dp[1000000];
ll n;
ll DIV = 1000000007;

void Solve()
{
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    for (ll i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIV;
    cout << dp[n] << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
