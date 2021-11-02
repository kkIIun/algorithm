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
        vector<ll> v(n + 1, 0);
        vector<ll> coin(n + 1, 0);
        for (ll j = 1; j <= m; j++)
            cin >> coin[j];

        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
                if (i - coin[j] >= 0)
                {
                    if (!v[i])
                        v[i] = v[i - coin[j]] + 1;
                    v[i] = min(v[i], v[i - coin[j]] + 1);
                }

        cout << v[n] << '\n';
    }
    return 0;
}
