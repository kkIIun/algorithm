#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, visited[1001][1001], ans;
ll Map[1001][1001];
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {-1, 0, 1, 0};
bool flag;

struct pos
{
    ll x, y;
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
    visited[0][0] = 1;
    q.push({0, 0});
    while (!q.empty())
    {
        ll x = q.front().x;
        ll y = q.front().y;
        q.pop();

        for (ll i = 0; i < 4; i++)
        {
            ll nextX = x + dx[i];
            ll nextY = y + dy[i];
            if (check(nextX, nextY))
                continue;
            if (Map[nextY][nextX] == 1)
            {
                if (visited[nextY][nextX])
                {
                    Map[nextY][nextX] = 0;
                    flag = true;
                }
                else
                    visited[nextY][nextX] = 1;
            }
            else if (!visited[nextY][nextX])
            {
                visited[nextY][nextX] = 1;
                q.push({nextX, nextY});
            }
        }
    }
    return;
}

void solve()
{
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> Map[i][j];

    while (1)
    {
        flag = false;
        memset(visited, 0, sizeof(visited));
        bfs();
        if (!flag)
            break;
        ans++;
    }
    cout << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
