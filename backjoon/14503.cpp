#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, Map[50][50], visited[50][50], ans = 0;

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {-1, 0, 1, 0};

struct pos
{
    ll y, x, dir;
};

void bfs(ll r, ll c, ll d)
{
    queue<pos> q;
    q.push({r, c, d});
    while (!q.empty())
    {
        pos cur = q.front();
        if (!visited[cur.y][cur.x])
        {
            visited[cur.y][cur.x] = 1;
            ans++;
        }
        q.pop();

        bool flag = false;
        for (ll i = 1; i <= 4; i++)
        {
            ll dir = (cur.dir - i + 4) % 4;
            ll nextY = cur.y + dy[dir];
            ll nextX = cur.x + dx[dir];
            if (visited[nextY][nextX] || Map[nextY][nextX])
                continue;
            q.push({nextY, nextX, dir});
            flag = true;
            break;
        }
        if (!flag)
        {
            ll dir = (cur.dir + 2) % 4;
            if (!Map[cur.y + dy[dir]][cur.x + dx[dir]])
                q.push({cur.y + dy[dir], cur.x + dx[dir], cur.dir});
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    ll r, c, d;
    cin >> r >> c >> d;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> Map[i][j];
    memset(visited, 0, sizeof(visited));
    bfs(r, c, d);
    cout << ans << '\n';
    return 0;
}