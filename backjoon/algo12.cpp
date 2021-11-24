#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

ll sz[1001], parent[1001];

struct Edges
{
    ll w, v1, v2;
};

bool cmp(Edges &a, Edges &b)
{
    if (a.w < b.w)
        return true;
    else
        return false;
}

ll find(ll i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void Union(ll i, ll j)
{
    if (sz[i] > sz[j])
    {
        parent[j] = i;
        sz[i] += sz[j];
    }
    else
    {
        parent[i] = j;
        sz[j] += sz[i];
    }
}

void solve()
{
    ll n, result = 0;
    vector<Edges> VE;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll k, m;
        cin >> k >> m;
        for (ll j = 1; j <= m; j++)
        {
            ll v, w;
            cin >> v >> w;
            VE.push_back({w, k, v});
        }
        sz[i] = 1;
        parent[i] = i;
    }

    sort(VE.begin(), VE.end(), cmp);

    for (ll i = 0; i < VE.size(); i++)
    {
        ll v1F = find(VE[i].v1);
        ll v2F = find(VE[i].v2);

        if (v1F == v2F)
            continue;
        Union(v1F, v2F);
        result += VE[i].w;
    }
    cout << result << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test;
    cin >> test;
    while (test--)
        solve();
    return 0;
}