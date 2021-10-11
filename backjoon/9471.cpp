#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll TC, n, m;
    cin >> TC;
    while (TC--)
    {
        cin >> n >> m;
        ll f1 = 1, f2 = 1, ans = 1;
        while (f2 != 1 or f1 != 0)
        {
            ll temp = f2;
            f2 = (f1 + f2) % m;
            f1 = temp;
            ans++;
        }
        cout << n << ' ' << ans << '\n';
    }
    return 0;
}
