#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, parent[100001][20], depth[100001], cost[100001];
vector<pair<ll, ll>> v[100001];

void setTree(ll start)
{
    for (auto next : v[start])
    {
        if (parent[start][0] == next.first)
            continue;
        depth[next.first] = depth[start] + 1;
        cost[next.first] = next.second + cost[start];
        parent[next.first][0] = start;
        setTree(next.first);
    }
}

void setParent()
{
    for (ll i = 1; i < 20; i++)
        for (ll j = 1; j <= n; j++)
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
}

void solve()
{
    ll a, b, c, t;
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    setTree(1);
    setParent();

    cin >> m;
    while (m--)
    {
        cin >> t >> a >> b;
        ll tempA = a, tempB = b;

        while (depth[tempA] != depth[tempB])
        {
            if (depth[tempA] < depth[tempB])
                swap(tempA, tempB);
            ll temp = depth[tempA] - depth[tempB];
            tempA = parent[tempA][(ll)log2(temp)];
        }

        while (tempA != tempB)
        {
            for (ll i = 19; i >= 0; i--)
                if (parent[tempA][i] != parent[tempB][i])
                {
                    tempA = parent[tempA][i];
                    tempB = parent[tempB][i];
                }
            tempA = parent[tempA][0];
            tempB = parent[tempB][0];
        }

        if (t == 1)
            cout << cost[a] + cost[b] - 2 * cost[tempA] << '\n';

        if (t == 2)
        {
            ll temp, left;
            cin >> temp;
            left = depth[a] - depth[tempA];
            if (temp <= left)
            {
                temp = depth[tempA] + left - temp + 1;
                while (depth[a] != temp)
                    a = parent[a][(ll)log2(depth[a] - temp)];
                cout << a << '\n';
            }
            else if (temp == left + 1)
                cout << tempA << '\n';
            else
            {
                temp -= left + 1;
                while (temp != depth[b] - depth[tempA])
                    b = parent[b][(ll)log2(depth[b] - temp - depth[tempA])];
                cout << b << '\n';
            }
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
