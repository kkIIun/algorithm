#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void)
{
    ll t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<ll>> v(n + 1, vector<ll>(m + 1, 0));
        vector<ll> coin(n + 1, 0);
        for (ll j = 1; j <= m; j++)
        {
            cin >> coin[j];
            v[0][j] = 1;
        }

        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
                if (i - coin[j] >= 0)
                {
                    v[i][j] = v[i][j - 1] + v[i - coin[j]][j];
                }
                else
                {
                    v[i][j] = v[i][j - 1];
                }

        cout << v[n][m] << '\n';
    }
    return 0;
}
