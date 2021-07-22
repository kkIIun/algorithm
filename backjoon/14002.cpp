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
ll n;
ll dp[1001][1001];
ll arr[1001], last[1001];
pair<ll, ll> ans = make_pair(1, 1);

void output(int i)
{
    if (last[i] != i)
        output(last[i]);
    cout << arr[i] << ' ';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        last[i] = i;
        dp[i][i] = 1;
    }

    for (ll i = 1; i <= n; i++)
        for (ll j = i; j <= n; j++)
            if (arr[i] < arr[j])
            {
                if (last[j] != j && dp[last[j]][j] > dp[last[i]][i] + 1)
                    continue;
                dp[i][j] = dp[last[i]][i] + 1;
                last[j] = i;
                if (ans.first < dp[i][j])
                {
                    ans.first = dp[i][j];
                    ans.second = j;
                }
            }

    cout << ans.first << endl;
    output(ans.second);
    return 0;
}
