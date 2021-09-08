#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, arr[100001];
pair<ll, ll> tree[262145];

pair<ll, ll> init(ll start, ll end, ll node)
{
    if (start == end)
    {
        tree[node] = make_pair(arr[start], arr[start]);
        return tree[node];
    }
    ll mid = (start + end) / 2;
    pair<ll, ll> left = init(start, mid, node * 2);
    pair<ll, ll> right = init(mid + 1, end, node * 2 + 1);
    tree[node] = make_pair(max(left.first, right.first), min(left.second, right.second));

    return tree[node];
}

pair<ll, ll> segTree(ll left, ll right, ll start, ll end, ll node)
{
    if (end == right && start == left)
        return tree[node];

    ll mid = (start + end) / 2;
    if (mid >= right)
        return segTree(left, right, start, mid, node * 2);
    if (mid < left)
        return segTree(left, right, mid + 1, end, node * 2 + 1);

    pair<ll, ll> leftTree = segTree(left, mid, start, mid, node * 2);
    pair<ll, ll> rightTree = segTree(mid + 1, right, mid + 1, end, node * 2 + 1);
    leftTree.first = leftTree.first > rightTree.first ? leftTree.first : rightTree.first;
    leftTree.second = leftTree.second < rightTree.second ? leftTree.second : rightTree.second;
    return leftTree;
}

void solve()
{
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    init(1, n, 1);
    ll a, b;
    while (m--)
    {
        cin >> a >> b;
        pair<ll, ll> temp = segTree(a, b, 1, n, 1);
        cout << temp.second << ' ' << temp.first << '\n';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    solve();
    return 0;
}
