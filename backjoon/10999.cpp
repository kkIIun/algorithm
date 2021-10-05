#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX_N 1000000
ll n, m, k;
vector<ll> tree, lazy;

void lazy_update(ll start, ll end, ll node)
{
    tree[node] += lazy[node] * (end - start + 1);
    if (start != end)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

ll init(vector<ll> &v, ll start, ll end, ll node)
{
    if (start == end)
    {
        tree[node] = v[start];
        return tree[node];
    }
    ll mid = (end + start) / 2;
    tree[node] = init(v, start, mid, node * 2) + init(v, mid + 1, end, node * 2 + 1);
    return tree[node];
}

ll update(ll start, ll end, ll node, ll left, ll right, ll diff)
{
    if (lazy[node])
        lazy_update(start, end, node);

    if (right < start || left > end)
        return tree[node];

    if (left <= start && end <= right)
    {
        lazy[node] += diff;
        lazy_update(start, end, node);
        return tree[node];
    }

    ll mid = (end + start) / 2;
    tree[node] = update(start, mid, node * 2, left, right, diff) + update(mid + 1, end, node * 2 + 1, left, right, diff);
    return tree[node];
}

ll sum(ll start, ll end, ll node, ll left, ll right)
{
    if (lazy[node])
        lazy_update(start, end, node);

    if (right < start || left > end)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (end + start) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;

    ll h = (ll)ceil(log2(n));
    ll tree_size = (1 << (h + 1)) - 1;
    tree.resize(tree_size);
    lazy.resize(tree_size);

    vector<ll> v(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    init(v, 1, n, 1);

    ll a, b, c, d;
    for (ll i = 1; i <= m + k; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            cin >> d;
            update(1, n, 1, b, c, d);
        }
        else
            cout << sum(1, n, 1, b, c) << '\n';
    }
    return 0;
}