#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ability[21][21], n, ans = 999999, team[21];

ll calc()
{
    ll link = 0, start = 0;
    for (ll i = 1; i <= n - 1; i++)
        for (ll j = i + 1; j <= n; j++)
            if (team[i] == team[j])
            {
                if (team[i])
                    link += ability[i][j] + ability[j][i];
                else
                    start += ability[i][j] + ability[j][i];
            }
    return abs(link - start);
}

void divide(ll start, ll depth)
{
    for (ll i = start; i <= n; i++)
    {
        team[i] = 1;
        if (depth == n / 2)
            ans = min(ans, calc());
        else
            divide(i + 1, depth + 1);
        team[i] = 0;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            cin >> ability[i][j];
    divide(1, 1);
    cout << ans << '\n';
    return 0;
}