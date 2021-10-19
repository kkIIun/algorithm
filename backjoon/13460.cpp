#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char Map[10][10];
ll ans = -1, visited[10][10][10][10];
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

struct info
{
    ll redY, redX, blueY, blueX, cnt;
};

ll bfs(pair<ll, ll> rStart, pair<ll, ll> bStart)
{
    queue<info> q;
    q.push({rStart.first, rStart.second, bStart.first, bStart.second, 0});
    while (!q.empty())
    {
        ll Ry = q.front().redY;
        ll Rx = q.front().redX;
        ll By = q.front().blueY;
        ll Bx = q.front().blueX;
        ll C = q.front().cnt;
        q.pop();
        if (C >= 10 || visited[Ry][Rx][By][Bx])
            continue;

        visited[Ry][Rx][By][Bx] = 1;
        for (ll i = 0; i < 4; i++)
        {
            bool flag1 = false;
            bool flag2 = false;
            ll nRy = Ry;
            ll nRx = Rx;
            ll nBy = By;
            ll nBx = Bx;
            while (1)
            {
                if (Map[nRy + dy[i]][nRx + dx[i]] != '#' && (nRy + dy[i] != nBy || nRx + dx[i] != nBx) || Map[nRy + dy[i]][nRx + dx[i]] == 'O')
                {
                    nRy += dy[i];
                    nRx += dx[i];
                }
                else if (Map[nBy + dy[i]][nBx + dx[i]] != '#' && (nBy + dy[i] != nRy || nBx + dx[i] != nRx) || Map[nBy + dy[i]][nBx + dx[i]] == 'O')
                {
                    nBy += dy[i];
                    nBx += dx[i];
                }
                else
                {
                    q.push({nRy, nRx, nBy, nBx, C + 1});
                    break;
                }

                if (Map[nRy][nRx] == 'O')
                {
                    flag1 = true;
                }

                if (Map[nBy][nBx] == 'O')
                {
                    flag2 = true;
                    break;
                }
            }
            if (flag1 && !flag2)
                return C + 1;
        }
    }
    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    pair<ll, ll> R, B;
    string s;
    for (ll i = 0; i < n; i++)
    {
        cin >> s;
        for (ll j = 0; j < m; j++)
        {
            if (s[j] == 'R')
                R = make_pair(i, j);
            else if (s[j] == 'B')
                B = make_pair(i, j);
            Map[i][j] = s[j];
        }
    }
    cout << bfs(R, B) << '\n';
    return 0;
}
