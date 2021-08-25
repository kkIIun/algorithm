#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, plan[1000], parent[201], cnt[201];

ll getParent(ll a)
{
    if (parent[a] == a)
        return a;
    return getParent(parent[a]);
}

void Union(ll a, ll b)
{
    a = getParent(a);
    b = getParent(b);
    if (cnt[a] < cnt[b])
        swap(a, b);
    if (a != b)
    {
        parent[b] = a;
        cnt[a] += cnt[b];
    }
}
void solve()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        parent[i] = i;
        cnt[i] = 1;
    }

    ll check;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
        {
            cin >> check;
            if (check)
                Union(i, j);
        }

    for (ll i = 0; i < m; i++)
        cin >> plan[i];

    for (ll i = 0; i < m - 1; i++)
    {
        if (getParent(plan[i]) != getParent(plan[i + 1]))
        {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
