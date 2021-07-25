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
vector<char> ans;
int dp[1001][1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string arr1, arr2;
    cin >> arr1 >> arr2;
    ll len1 = arr1.length();
    ll len2 = arr2.length();
    for (ll i = 1; i <= len1; i++)
        for (ll j = 1; j <= len2; j++)
        {
            if (arr2[j - 1] == arr1[i - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    cout << dp[len1][len2] << endl;

    while (dp[len1][len2] != 0)
    {

        if (dp[len1][len2] == dp[len1][len2 - 1])
            len2--;
        else if (dp[len1][len2] == dp[len1 - 1][len2])
            len1--;
        else if (dp[len1][len2] - 1 == dp[len1 - 1][len2 - 1])
        {
            ans.push_back(arr1[len1 - 1]);
            len1--;
            len2--;
        }
    }
    for (ll i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}
