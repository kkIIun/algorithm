#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool flag;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll temp = x1 * y2 + y1 * x3 + x2 * y3 - (y2 * x3 + x1 * y3 + y1 * x2);
    if (temp < 0)
        return -1;
    else if (temp == 0)
        return 0;
    else
        return 1;
}

void solve()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    ll ccw1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
    ll ccw2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
    if (ccw1 <= 0 && ccw2 <= 0)
    {
        if (ccw1 == 0 && ccw2 == 0)
        {
            if (x1 == x3)
            {
                if (y1 > y2)
                {
                    swap(x1, x2);
                    swap(y1, y2);
                }
                if (y3 > y4)
                {
                    swap(x3, x4);
                    swap(y3, y4);
                }
                if (y1 <= y4 && y3 <= y2)
                    cout << 1 << '\n';
                else
                    cout << 0 << '\n';
            }
            else
            {
                if (x1 > x2)
                {
                    swap(x1, x2);
                    swap(y1, y2);
                }
                if (x3 > x4)
                {
                    swap(x3, x4);
                    swap(y3, y4);
                }
                if (x1 <= x4 && x3 <= x2)
                    cout << 1 << '\n';
                else
                    cout << 0 << '\n';
            }
        }
        else
            cout << 1 << '\n';
    }

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
