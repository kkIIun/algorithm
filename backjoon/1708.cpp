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

    stack<ll> st;
    st.push(0);
    st.push(1);

    ll next = 2;
    while (next < n)
    {
        while (st.size() >= 2)
        {
            ll second = st.top();
            st.pop();
            ll first = st.top();

            if (ccw(v[first], v[second], v[next]))
            {
                st.push(second);
                break;
            }
        }
        st.push(next++);
    }
    cout << st.size() << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
