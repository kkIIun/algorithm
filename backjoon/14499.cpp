#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dx[5] = {0, 1, -1, 0, 0};
ll dy[5] = {0, 0, 0, -1, 1};

int main(void)
{
    ll dice[6] = {0}, n, m, x, y, k, dir;
    cin >> n >> m >> y >> x >> k;
    vector<vector<ll>> map(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> map[i][j];
    while (k--)
    {
        cin >> dir;
        if (x + dx[dir] < 0 || x + dx[dir] >= m || y + dy[dir] < 0 || y + dy[dir] >= n)
            continue;
        x += dx[dir];
        y += dy[dir];

        if (dir == 1)
        {
            swap(dice[4], dice[1]);
            swap(dice[1], dice[5]);
            swap(dice[5], dice[3]);
        }
        else if (dir == 2)
        {
            swap(dice[5], dice[1]);
            swap(dice[1], dice[4]);
            swap(dice[4], dice[3]);
        }
        else if (dir == 3)
        {
            swap(dice[3], dice[2]);
            swap(dice[1], dice[2]);
            swap(dice[0], dice[1]);
        }
        else if (dir == 4)
        {
            swap(dice[1], dice[2]);
            swap(dice[3], dice[2]);
            swap(dice[0], dice[3]);
        }
        if (map[y][x])
        {
            dice[1] = map[y][x];
            map[y][x] = 0;
        }
        else
            map[y][x] = dice[1];
        cout << dice[3] << '\n';
    }
    return 0;
}