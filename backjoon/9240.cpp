#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 100002

struct INFO
{
    ll x, y, dx, dy;
    INFO(ll x1, ll y1) : x(x1), y(y1), dx(1), dy(0) {}
};

ll n;
ll ans = 0;
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

bool cccw(INFO a, INFO b, INFO c, INFO d)
{
    d.x -= (c.x - b.x);
    d.y -= (c.y - b.y);
    return ccw(a, b, d);
}

ll dist(INFO &a, INFO &b)
{
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

void solve()
{
    cin >> n;

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

    vector<ll> idx;
    idx.push_back(0);
    idx.push_back(1);

    ll next = 2;
    while (next < n)
    {
        while (idx.size() >= 2)
        {
            ll second = idx.back();
            idx.pop_back();
            ll first = idx.back();

            if (ccw(v[first], v[second], v[next]))
            {
                idx.push_back(second);
                break;
            }
        }
        idx.push_back(next++);
    }

    ll j = 1, ln = idx.size();
    for (ll i = 0; i < ln; i++)
    {
        while (cccw(v[idx[i]], v[idx[(i + 1) % ln]], v[idx[j % ln]], v[idx[(j + 1) % ln]]))
        {
            ans = max(ans, dist(v[idx[i]], v[idx[j % ln]]));
            j++;
        }
        ans = max(ans, dist(v[idx[i]], v[idx[j % ln]]));
    }
    printf("%.6lf\n", sqrt(ans));
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
