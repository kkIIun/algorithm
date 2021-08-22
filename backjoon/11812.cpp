#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, q;

void solve()
{
    scanf("%lld %lld %lld", &n, &k, &q);
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        if (k == 1)
        {
            printf("%lld\n", abs(x - y));
            continue;
        }
        ll ans = 0;
        while (x != y)
        {
            if (x < y)
                swap(x, y);

            x = (x - 2) / k + 1;
            ans++;
        }
        printf("%lld\n", ans);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
