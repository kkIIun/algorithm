#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, visited[1001][1001][2];
ll Map[1001][1001];
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {-1, 0, 1, 0};

struct pos
{
    ll x, y, dist, block;
};

bool check(ll x, ll y)
{
    if (x < 0 || x >= m || y < 0 || y >= n)
        return true;
    return false;
}

void bfs()
{
    queue<pos> q;
    visited[0][0][0] = 1;
    q.push({0, 0, 1, 0});
    while (!q.empty())
    {
        ll x = q.front().x;
        ll y = q.front().y;
        ll dist = q.front().dist;
        ll block = q.front().block;
        q.pop();

        if (x == m - 1 && y == n - 1)
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
            if (Map[nextY][nextX] == 1 && !block && !visited[nextY][nextX][block + 1])
            {
                visited[nextY][nextX][block + 1] = dist + 1;
                q.push({nextX, nextY, dist + 1, block + 1});
            }
            else if (Map[nextY][nextX] == 0 && !visited[nextY][nextX][block])
            {
                visited[nextY][nextX][block] = dist + 1;
                q.push({nextX, nextY, dist + 1, block});
            }
        }
    }
    cout << -1 << '\n';
    return;
}

void solve()
{
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        string In;
        cin >> In;
        for (ll j = 0; j < m; j++)
            Map[i][j] = In[j] - '0';
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
