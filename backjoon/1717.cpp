#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, parent[1000001], cnt[1000001];

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

    ll type, a, b;
    while (m--)
    {
        cin >> type >> a >> b;
        if (type)
        {
            if (getParent(a) == getParent(b))
                cout << "YES"
                     << "\n";
            else
                cout << "NO"
                     << "\n";
        }
        else
            Union(a, b);
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
