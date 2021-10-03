#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k, tree[26214500], DIV = 1000000007;
vector<ll> v;

void init(ll start, ll end, ll node)
{
    ll sum = 1;
    for (ll i = start; i <= end; i++)
        sum = (sum * v[i]) % DIV;
    tree[node] = sum;
    if (start == end)
        return;
    ll mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
}

ll calcTree(ll start, ll end, ll node, ll left, ll right)
{
    if (left <= start && end <= right)
        return tree[node];

    if (start > right || end < left)
        return 1;

    ll mid = (start + end) / 2;
    return (calcTree(start, mid, node * 2, left, right) % DIV * calcTree(mid + 1, end, node * 2 + 1, left, right) % DIV) % DIV;
}

ll setTree(ll start, ll end, ll node, ll idx, ll val)
{
    if (idx == start && end == idx)
    {
        tree[node] = v[idx];
        return tree[node];
    }

    if (start > idx || end < idx)
        return tree[node];

    ll mid = (start + end) / 2;
    tree[node] = (setTree(start, mid, node * 2, idx, val) * setTree(mid + 1, end, node * 2 + 1, idx, val)) % DIV;
    return tree[node];
}

void solve()
{
    cin >> n >> m >> k;
    v.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> v[i];

    init(1, n, 1);

    ll a, b, c;
    for (ll i = 0; i < m + k; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            v[b] = c;
            setTree(1, n, 1, b, c);
        }
        else
            cout << calcTree(1, n, 1, b, c) << '\n';
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