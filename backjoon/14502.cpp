#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pos
{
    ll y, x;
};

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
ll Map[8][8], n, m, safe = 0, ans = 0;

void bfs(vector<pos> start, ll i, ll j, ll i1, ll j1, ll i2, ll j2)
{
    queue<pos> q;
    ll visited[8][8], plt = 3;
    memset(visited, 0, sizeof(visited));

    for (ll i = 0; i < start.size(); i++)
    {
        q.push(start[i]);
        visited[start[i].y][start[i].x] = 1;
    }
    visited[i][j] = 1;
    visited[i1][j1] = 1;
    visited[i2][j2] = 1;
    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll nextX = cur.x + dx[i];
            ll nextY = cur.y + dy[i];
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || Map[nextY][nextX] != 0 || visited[nextY][nextX])
                continue;
            visited[nextY][nextX] = 1;
            plt++;
            q.push({nextY, nextX});
        }
    }
    ans = max(ans, safe - plt);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<pos> start;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 0)
                safe++;
            if (Map[i][j] == 2)
                start.push_back({i, j});
        }
    for (ll i = 0; i < m * n - 2; i++)
        for (ll j = i + 1; j < m * n - 1; j++)
            for (ll k = j + 1; k < m * n; k++)
                if (!Map[i / m][i % m] && !Map[j / m][j % m] && !Map[k / m][k % m])
                    bfs(start, i / m, i % m, j / m, j % m, k / m, k % m);
    cout << ans << '\n';
    return 0;
}