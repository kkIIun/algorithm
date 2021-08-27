#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t, f, parent[200001], cnt[200001];
string f1, f2;

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
    map<string, ll> hash;
    cin >> f;
    for (ll i = 1; i <= 2 * f; i++)
    {
        parent[i] = i;
        cnt[i] = 1;
    }

    ll idx = 1;
    while (f--)
    {
        cin >> f1 >> f2;
        if (hash.find(f1) == hash.end())
        {
            hash[f1] = idx;
            idx++;
        }
        if (hash.find(f2) == hash.end())
        {
            hash[f2] = idx;
            idx++;
        }
        ll id1 = hash[f1];
        ll id2 = hash[f2];
        Union(id1, id2);
        ll root = getParent(id1);
        cout << cnt[root] << '\n';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
