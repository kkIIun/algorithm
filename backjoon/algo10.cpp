#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef long long ll;

ll arr[1001][1001], length[1001], touch[1001], n;

ll minIdx()
{
    ll min = 100000, idx = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (length[i] > 0 && length[i] < min)
        {
            min = length[i];
            idx = i;
        }
    }
    return idx;
}

ll dijkstra(ll start)
{
    for (ll i = 1; i <= n; i++)
        if (arr[start][i] != -1 && arr[start][i] < length[i])
        {
            length[i] = arr[start][i];
            touch[i] = start;
        }

    while (1)
    {
        ll idx = minIdx();
        if (idx == -1)
            break;
        for (ll i = 1; i <= n; i++)
            if (arr[idx][i] != -1 && arr[idx][i] + length[idx] < length[i])
            {
                length[i] = arr[idx][i] + length[idx];
                touch[i] = idx;
            }
        length[idx] = -length[idx];
    }
    ll result = 0;
    for (ll i = 1; i <= n; i++)
        result += arr[touch[i]][i];

    return result;
}

void solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll k, m;
        cin >> k >> m;
        for (ll j = 1; j <= m; j++)
        {
            ll v, w;
            cin >> v >> w;
            arr[k][v] = w;
        }
        length[i] = 100000;
        touch[i] = i;
    }
    length[1] = 0;
    cout << dijkstra(1) + 1 << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll test;
    cin >> test;
    while (test--)
    {
        memset(arr, -1, sizeof(arr));
        solve();
    }
    return 0;
}