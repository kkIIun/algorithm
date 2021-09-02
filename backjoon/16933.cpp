#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k, visited[1001][1001][11];
ll Map[1001][1001];
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {-1, 0, 1, 0};

struct pos
{
    ll x, y, dist, block;
    bool day;
};

bool check(ll x, ll y)
{
    if (x < 1 || x > m || y < 1 || y > n)
        return true;
    return false;
}

void bfs()
{
    queue<pos> q;
    visited[1][1][0] = 1;
    q.push({1, 1, 1, 0, true});
    while (!q.empty())
    {
        ll x = q.front().x;
        ll y = q.front().y;
        ll dist = q.front().dist;
        ll block = q.front().block;
        ll day = q.front().day;
        q.pop();

        if (x == m && y == n)
        {
            cout << dist << '\n';
            return;
        }

        for (ll i = 0; i < 4; i++)
        {
            ll nextX = x + dx[i];
            ll nextY = y + dy[i];
            if (check(nextX, nextY))
                continue;
            if (Map[nextY][nextX] == 1 && block < k && !visited[nextY][nextX][block + 1])
            {
                if (day)
                {
                    visited[nextY][nextX][block + 1] = dist + 1;
                    q.push({nextX, nextY, dist + 1, block + 1, !day});
                }
                else
                {
                    visited[y][x][block + 1] = dist + 1;
                    q.push({x, y, dist + 1, block, !day});
                }
            }
            else if (Map[nextY][nextX] == 0 && !visited[nextY][nextX][block])
            {
                visited[nextY][nextX][block] = dist + 1;
                q.push({nextX, nextY, dist + 1, block, !day});
            }
        }
    }
    cout << -1 << '\n';
    return;
}

void solve()
{
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (ll j = 1; j <= m; j++)
            Map[i][j] = str[j - 1] - '0';
    }
    bfs();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
