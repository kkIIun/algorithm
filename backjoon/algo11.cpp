#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef long long ll;

ll nearV(ll distance[1001], ll n)
{
    ll min = 100000, near = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (distance[i] > 0 && distance[i] < min)
        {
            min = distance[i];
            near = i;
        }
    }
    return near;
}

ll Prim(ll start, ll n, ll weight[][1001], ll distance[], ll near[])
{
    for (ll i = 2; i <= n; i++)
        if (weight[start][i] < distance[i])
        {
            distance[i] = weight[start][i];
            near[i] = start;
        }

    for (ll i = 0; i < n - 1; i++)
    {
        ll idx = nearV(distance, n);
        for (ll i = 2; i <= n; i++)
            if (weight[idx][i] < distance[i])
            {
                distance[i] = weight[idx][i];
                near[i] = idx;
            }
        distance[idx] = -distance[idx];
    }
    ll result = 0;
    for (ll i = 2; i <= n; i++)
        result -= distance[i];

    return result;
}

void solve()
{
    ll n, weight[1001][1001], distance[1001], near[1001];
    fill(&weight[0][0], &weight[1000][1001], 101);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll k, m;
        cin >> k >> m;
        for (ll j = 1; j <= m; j++)
        {
            ll v, w;
            cin >> v >> w;
            weight[k][v] = w;
        }
        distance[i] = 101;
        near[i] = i;
    }
    cout << Prim(1, n, weight, distance, near) << '\n';
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