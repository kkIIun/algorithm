#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
ll n, ans = 0;
vector<vector<ll>> board;

struct info
{
    vector<vector<ll>> map;
    ll cnt;
};

void move(vector<vector<ll>> map, ll cnt, queue<info> &q)
{
    for (ll i = 0; i < 4; i++)
    {
        vector<vector<ll>> nMap = map;
        switch (i)
        {
        case 0:
            for (ll r = n - 1; r >= 0; r--)
            {
                for (ll c = n - 1; c >= 1; c--)
                {
                    if (!nMap[r][c])
                        continue;
                    ll temp = c - 1;
                    while (nMap[r][temp] == 0 && temp > 0)
                        temp--;
                    if (nMap[r][temp] == nMap[r][c])
                    {
                        nMap[r][c] *= 2;
                        nMap[r][temp] = 0;
                    }
                }

                for (ll c = n - 1; c >= 0; c--)
                    if (nMap[r][c])
                    {
                        ll nc = c, nr = r;
                        ans = max(ans, nMap[nr][nc]);
                        while (nc + dx[i] < n && nr + dy[i] < n && nMap[nr + dy[i]][nc + dx[i]] == 0)
                        {
                            nMap[nr + dy[i]][nc + dx[i]] = nMap[nr][nc];
                            nMap[nr][nc] = 0;
                            nc += dx[i];
                            nr += dy[i];
                        }
                    }
            }
            break;
        case 1:
            for (ll c = n - 1; c >= 0; c--)
            {
                for (ll r = n - 1; r >= 1; r--)
                {
                    if (!nMap[r][c])
                        continue;
                    ll temp = r - 1;
                    while (nMap[temp][c] == 0 && temp > 0)
                        temp--;
                    if (nMap[temp][c] == nMap[r][c])
                    {
                        nMap[r][c] *= 2;
                        nMap[temp][c] = 0;
                    }
                }
                for (ll r = n - 1; r >= 0; r--)
                    if (nMap[r][c])
                    {
                        ll nc = c, nr = r;
                        ans = max(ans, nMap[nr][nc]);
                        while (nc + dx[i] < n && nr + dy[i] < n && nMap[nr + dy[i]][nc + dx[i]] == 0)
                        {
                            nMap[nr + dy[i]][nc + dx[i]] = nMap[nr][nc];
                            nMap[nr][nc] = 0;
                            nc += dx[i];
                            nr += dy[i];
                        }
                    }
            }
            break;
        case 2:
            for (ll r = 0; r < n; r++)
            {
                for (ll c = 0; c < n - 1; c++)
                {
                    if (!nMap[r][c])
                        continue;
                    ll temp = c + 1;
                    while (nMap[r][temp] == 0 && temp < n - 1)
                        temp++;
                    if (nMap[r][temp] == nMap[r][c])
                    {
                        nMap[r][c] *= 2;
                        nMap[r][temp] = 0;
                    }
                }

                for (ll c = 0; c < n; c++)
                    if (nMap[r][c])
                    {
                        ll nc = c, nr = r;
                        ans = max(ans, nMap[nr][nc]);
                        while (nc + dx[i] >= 0 && nr + dy[i] >= 0 && nMap[nr + dy[i]][nc + dx[i]] == 0)
                        {
                            nMap[nr + dy[i]][nc + dx[i]] = nMap[nr][nc];
                            nMap[nr][nc] = 0;
                            nc += dx[i];
                            nr += dy[i];
                        }
                    }
            }
            break;
        case 3:
            for (ll c = 0; c < n; c++)
            {
                for (ll r = 0; r < n - 1; r++)
                {
                    if (!nMap[r][c])
                        continue;
                    ll temp = r + 1;
                    while (nMap[temp][c] == 0 && temp < n - 1)
                        temp++;
                    if (nMap[temp][c] == nMap[r][c])
                    {
                        nMap[r][c] *= 2;
                        nMap[temp][c] = 0;
                    }
                }
                for (ll r = 0; r < n; r++)
                    if (nMap[r][c])
                    {
                        ll nc = c, nr = r;
                        ans = max(ans, nMap[nr][nc]);
                        while (nc + dx[i] >= 0 && nr + dy[i] >= 0 && nMap[nr + dy[i]][nc + dx[i]] == 0)
                        {
                            nMap[nr + dy[i]][nc + dx[i]] = nMap[nr][nc];
                            nMap[nr][nc] = 0;
                            nc += dx[i];
                            nr += dy[i];
                        }
                    }
            }
            break;
        }
        q.push({nMap, cnt + 1});
    }
}

void bfs()
{
    queue<info> q;
    q.push({board, 0});
    while (!q.empty())
    {
        vector<vector<ll>> cur = q.front().map;
        ll cnt = q.front().cnt;
        q.pop();
        if (cnt >= 5)
            continue;
        move(cur, cnt, q);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    board.assign(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> board[i][j];
    bfs();
    cout << ans << '\n';
    return 0;
}