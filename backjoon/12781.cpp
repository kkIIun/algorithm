#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll temp1 = x1 * y2 + y1 * x3 + x2 * y3 - (y2 * x3 + x1 * y3 + y1 * x2);
    if (temp1 < 0)
        return -1;
    else
        return 1;
}

void solve()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0)
        cout << 1 << '\n';
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
