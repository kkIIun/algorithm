#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n, m;
vector<vector<ll>> dp;
vector<ll> v;

ll recur(ll start, ll end)
{
    if (dp[start][end])
        return dp[start][end];
    for (ll i = 1; i <= m; i++)
        if (v[i] > start && v[i] < end)
        {
            if (!dp[start][end])
                dp[start][end] = recur(start, v[i]) + recur(v[i], end);
            else
                dp[start][end] = min(dp[start][end], recur(start, v[i]) + recur(v[i], end));
        }
    cout << start << ' ' << end << ' ' << dp[start][end] << '\n';
    return dp[start][end];
}

int main(void)
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        dp.assign(n + 1, vector<ll>(n + 1, 0));
        v.assign(m + 1, 0);
        for (ll i = 1; i <= m; i++)
        {
            cin >> v[i];
            dp[v[i - 1]][v[i]] = v[i] - v[i - 1];
        }
        dp[v[m]][n] = n - v[m];
        recur(0, n);
        cout << dp[0][n] << '\n';
    }
    return 0;
}
