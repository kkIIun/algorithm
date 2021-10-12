#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define pi 3.1415926535

struct INFO
{
    ll x, y, dx, dy;
    INFO(ll x1, ll y1) : x(x1), y(y1), dx(1), dy(0) {}
};

ll n, l;
double ans = 0;
vector<INFO> v;

bool cmp(INFO &a, INFO &b)
{
    if (a.dy * b.dx != a.dx * b.dy)
        return a.dy * b.dx < a.dx * b.dy;

    if (a.y != b.y)
        return a.y < b.y;

    return a.x < b.x;
}

bool ccw(INFO &a, INFO &b, INFO &c)
{
    ll temp = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (temp > 0)
        return true;
    else
        return false;
}

double abs(INFO &a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

void solve()
{
    cin >> n >> l;

    ll x, y;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(INFO(x, y));
    }

    sort(v.begin(), v.end(), cmp);

    for (ll i = 1; i < n; i++)
    {
        v[i].dx = v[i].x - v[0].x;
        v[i].dy = v[i].y - v[0].y;
    }

    sort(v.begin() + 1, v.end(), cmp);

    vector<INFO> cv;
    cv.push_back(v[0]);
    cv.push_back(v[1]);

    ll next = 2;
    while (next < n)
    {
        while (cv.size() >= 2)
        {
            INFO second = cv.back();
            cv.pop_back();
            INFO first = cv.back();

            if (ccw(first, second, v[next]))
            {
                cv.push_back(second);
                break;
            }
        }
        cv.push_back(v[next++]);
    }

    ll ln = cv.size(), sec = 1, thi = 2;
    for (ll fir = 0; fir < ln; fir++, sec++, thi++)
    {
        INFO A(cv[fir].x - cv[sec % ln].x, cv[fir].y - cv[sec % ln].y);
        INFO B(cv[thi % ln].x - cv[sec % ln].x, cv[thi % ln].y - cv[sec % ln].y);
        double deg = 0.5 - acos((A.x * B.x + A.y * B.y) / (abs(A) * abs(B))) / (2 * pi);
        ans += abs(A) + 2 * pi * l * deg;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    cout << round(ans) << '\n';
    return 0;
}
