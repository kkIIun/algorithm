#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k, Map[1025][1025];
ll tree[3030][3030];

void Colinit(ll start, ll end, ll Rnode, ll Cnode, ll rowS, ll rowE)
{
    ll sum = 0;
    for (ll i = rowS; i <= rowE; i++)
        for (ll j = start; j <= end; j++)
            sum += Map[i][j];

    tree[Rnode][Cnode] = sum;
    if (start == end)
        return;
    ll mid = (start + end) / 2;
    Colinit(start, mid, Rnode, Cnode * 2, rowS, rowE);
    Colinit(mid + 1, end, Rnode, Cnode * 2 + 1, rowS, rowE);
}

void init(ll start, ll end, ll node)
{
    Colinit(1, n, node, 1, start, end);
    if (start == end)
        return;
    ll mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
}

ll calcColTree(ll start, ll end, ll Rnode, ll Cnode, ll left, ll right)
{
    if (left <= start && end <= right)
        return tree[Rnode][Cnode];

    if (start > right || end < left)
        return 0;

    ll mid = (start + end) / 2;
    return (calcColTree(start, mid, Rnode, Cnode * 2, left, right) + calcColTree(mid + 1, end, Rnode, Cnode * 2 + 1, left, right));
}

ll calcRowTree(ll start, ll end, ll Rnode, ll x1, ll y1, ll x2, ll y2)
{
    if (y1 <= start && end <= y2)
        return calcColTree(1, n, Rnode, 1, x1, x2);

    if (start > y2 || end < y1)
        return 0;

    ll mid = (start + end) / 2;
    return calcRowTree(start, mid, Rnode * 2, x1, y1, x2, y2) + calcRowTree(mid + 1, end, Rnode * 2 + 1, x1, y1, x2, y2);
}

ll setColTree(ll start, ll end, ll Rnode, ll Cnode, ll x, ll y, ll val)
{
    if (x == start && end == x)
    {
        tree[Rnode][Cnode] += val - Map[y][x];
        return tree[Rnode][Cnode];
    }

    if (start > x || end < x)
        return tree[Rnode][Cnode];

    ll mid = (start + end) / 2;
    tree[Rnode][Cnode] = (setColTree(start, mid, Rnode, Cnode * 2, x, y, val) + setColTree(mid + 1, end, Rnode, Cnode * 2 + 1, x, y, val));
    return tree[Rnode][Cnode];
}

void setRowTree(ll start, ll end, ll node, ll x, ll y, ll val)
{
    if (y >= start && end >= y)
        setColTree(1, n, node, 1, x, y, val);

    if (start > y || end < y || start == end)
        return;

    ll mid = (start + end) / 2;
    setRowTree(start, mid, node * 2, x, y, val);
    setRowTree(mid + 1, end, node * 2 + 1, x, y, val);
}

void solve()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            cin >> Map[i][j];
    init(1, n, 1);

    ll w, x, y, x1, y1, c;
    while (m--)
    {
        cin >> w >> x >> y;
        if (w == 1)
        {
            cin >> x1 >> y1;
            cout << calcRowTree(1, n, 1, x, y, x1, y1) << '\n';
        }
        else
        {
            cin >> c;
            setRowTree(1, n, 1, x, y, c);
            Map[y][x] = c;
        }
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