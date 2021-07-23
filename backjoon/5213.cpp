#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll;
ll n;
ll map[501][1001];
pair<ll, ll> visited[501 * 501];
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

void output(ll num)
{
    if (num == 1)
    {
        cout << 1 << ' ';
    }
    else
    {
        output(visited[num].second);
        cout << num << ' ';
    }
}

int bfs()
{
    bool flag = false;
    memset(visited, -1, sizeof(visited));
    queue<tuple<ll, ll, ll>> q;
    q.push(make_tuple(0, 0, 1));
    q.push(make_tuple(0, 1, 1));
    visited[1] = make_pair(1, 1);
    while (!q.empty())
    {
        ll y = get<0>(q.front());
        ll x = get<1>(q.front());
        ll cnt = get<2>(q.front());
        ll current_tile = y % 2 == 0 ? y / 2 * (2 * n - 1) + x / 2 + 1 : y / 2 * (2 * n - 1) + n + (x - 1) / 2 + 1;
        q.pop();
        if (y == n - 1 && x == 2 * n - 2)
            flag = true;
        for (ll i = 0; i < 4; i++)
        {
            ll ny = y + dy[i];
            ll nx = x + dx[i];
            ll tile = ny % 2 == 0 ? ny / 2 * (2 * n - 1) + nx / 2 + 1 : ny / 2 * (2 * n - 1) + n + (nx - 1) / 2 + 1;
            if (ny < 0 or nx < 0 or ny >= n or nx >= 2 * n or visited[tile].first != -1)
                continue;

            if (map[y][x] == map[ny][nx])
            {
                if (ny % 2)
                {
                    nx = (nx - 1) / 2 * 2 + 1;
                    visited[tile] = make_pair(cnt + 1, current_tile);
                    q.push(make_tuple(ny, nx, cnt + 1));
                    q.push(make_tuple(ny, nx + 1, cnt + 1));
                }
                else
                {
                    nx = nx / 2 * 2;
                    visited[tile] = make_pair(cnt + 1, current_tile);
                    q.push(make_tuple(ny, nx, cnt + 1));
                    q.push(make_tuple(ny, nx + 1, cnt + 1));
                }
            }
        }
    }
    if (flag)
        return n * n - n / 2;
    else
    {
        for (ll k = n * n - n / 2; k > 0; k--)
        {
            if (visited[k].first != -1)
                return k;
        }
    }
    return 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        if (i % 2)
            for (ll j = 1; j < 2 * n - 1; j++)
                cin >> map[i][j];
        else
            for (ll j = 0; j < 2 * n; j++)
                cin >> map[i][j];
    }
    ll ans = bfs();
    cout << visited[ans].first << endl;
    output(ans);
    return 0;
}
