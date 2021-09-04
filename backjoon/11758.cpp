#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll temp = x1 * y2 - x1 * y3 - y1 * x2 + y1 * x3 + x2 * y3 - y2 * x3;
    if (temp > 0)
        cout << 1 << '\n';
    else if (temp < 0)
        cout << -1 << '\n';
    else
        cout << 0 << '\n';
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
