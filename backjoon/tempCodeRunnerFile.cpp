#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 198654321;
vector<pair<ll, ll>> v;
ll n, dp[101][101], arr[51][2];

void Solve()
{
    while (!v.empty())
    {
        ll start = v.back().first;
        ll end = v.back().second;
        v.pop_back();

        dp[start][end]++;
        dp[end][start]++;
        for (ll i = end - 1; i > start + 1; --i)
            for (ll j = start + 1; j < i; ++j)
            {
                dp[j][i] = max(dp[j][i], dp[start][end]);
                dp[i][j] = max(dp[i][j], dp[start][end]);
            }

        ll i = ((start - 1) == 0 ? 100 : start - 1);
        while (i != end)
        {
            ll j = ((end + 1) == 101 ? 1 : end + 1);
            while (j != i)
            {
                dp[j][i] = max(dp[j][i], dp[start][end]);
                dp[i][j] = max(dp[i][j], dp[start][end]);
                j = ((j + 1) == 101 ? 1 : j + 1);
            }
            i = ((i - 1) == 0 ? 100 : i - 1);
        }
    }
    ll ans = 0;
    for (ll i = 100; i > 1; --i)
        for (ll j = 1; j < i; ++j)
            ans = max(ans, dp[j][i]);

    cout << ans << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll tempA, tempB, a, b;
        cin >> tempA >> tempB;
        a = min(tempA, tempB);
        b = max(tempA, tempB);
        v.push_back(make_pair(a, b));
    }
    Solve();
    return 0;
}
