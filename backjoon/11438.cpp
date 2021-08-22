#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, parent[100001][18], depth[100001];
vector<ll> v[100001];

void setTree(ll start)
{
    for (ll next : v[start])
        if (depth[next] == -1)
        {
            parent[next][0] = start;
            depth[next] = depth[start] + 1;
            setTree(next);
        }
}

void setParent()
{
    for (ll k = 0; k <= 16; k++)
        for (ll i = 1; i <= n; i++)
            if (parent[i][k] != -1)
                parent[i][k + 1] = parent[parent[i][k]][k];
}

void solve()
{
    ll a, b;
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(parent, -1, sizeof(parent));
    fill(depth, depth + n + 1, -1);
    depth[1] = 0;

    setTree(1);
    setParent();
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;

        if (depth[a] < depth[b])
            swap(a, b);
        ll diff = depth[a] - depth[b];

        for (ll j = 0; diff; j++)
        {
            if (diff % 2)
                a = parent[a][j];
            diff /= 2;
        }
        while (a != b)
        {
            for (ll k = 17; k >= 0; k--)
                if (parent[a][k] != parent[b][k])
                {
                    a = parent[a][k];
                    b = parent[b][k];
                    break;
                }

            a = parent[a][0];
            b = parent[b][0];
        }
        cout << a << '\n';
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
