#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long ll;

vector<pair<ll, ll>> cctv;

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};
ll row, col;

void print2d(vector<vector<ll>> map)
{
    for (ll i = 0; i < row; i++)
    {
        for (ll j = 0; j < col; j++)
            cout << map[i][j];
        cout << '\n';
    }
    cout << '\n';
}

ll move(ll x, ll y, ll dir, vector<vector<ll>> &map)
{
    ll result = 0;
    while (1)
    {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= col || y < 0 || y >= row || map[y][x] != 0)
            break;
        map[y][x] = 6;
        result++;
    }

    return result;
}

ll solve(vector<vector<ll>> &map, ll idx)
{
    print2d(map);
    if (idx >= cctv.size())
        return 0;
    ll x = cctv[idx].first;
    ll y = cctv[idx].second;
    cout << map[x][y] << '\n';
    ll result = 0;

    if (map[x][y] == 1)
    {
        for (ll i = 0; i < 4; i++)
        {
            vector<vector<ll>> v(map.size(), vector<ll>(map[0].size(), 0));
            copy(map.begin(), map.end(), v.begin());
            result = max(result, move(x, y, i, v) + solve(v, idx + 1));
        }
    }
    else if (map[x][y] == 2)
    {
        for (ll i = 0; i < 2; i++)
        {
            vector<vector<ll>> v(map.size(), vector<ll>(map[0].size(), 0));
            copy(map.begin(), map.end(), v.begin());
            ll cnt = 0;
            cnt += move(x, y, i + 2, v) + move(x, y, i, v);
            result = max(result, cnt + solve(v, idx + 1));
        }
    }
    else if (map[x][y] == 3)
    {
        for (ll i = 0; i < 4; i++)
        {
            vector<vector<ll>> v(map.size(), vector<ll>(map[0].size(), 0));
            copy(map.begin(), map.end(), v.begin());
            ll cnt = 0;
            cnt += move(x, y, (i + 1) % 4, v) + move(x, y, i, v);
            result = max(result, cnt + solve(v, idx + 1));
        }
    }
    else if (map[x][y] == 4)
    {
        for (ll i = 0; i < 4; i++)
        {
            vector<vector<ll>> v(map.size(), vector<ll>(map[0].size(), 0));
            copy(map.begin(), map.end(), v.begin());
            ll cnt = 0;
            cnt += move(x, y, (i + 1) % 4, v) + move(x, y, i, v) + move(x, y, (i + 3) % 4, v);
            result = max(result, cnt + solve(v, idx + 1));
        }
    }
    else if (map[x][y] == 5)
    {
        ll cnt = 0;
        vector<vector<ll>> v(map.size(), vector<ll>(map[0].size(), 0));
        copy(map.begin(), map.end(), v.begin());
        for (ll i = 0; i < 4; i++)
            cnt += move(x, y, i, v);
        result = max(result, cnt + solve(v, idx + 1));
    }
    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> row >> col;
    ll total = row * col;
    vector<vector<ll>> map(row, vector<ll>(col, 0));
    for (ll i = 0; i < row; i++)
        for (ll j = 0; j < col; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0 && map[i][j] != 6)
                cctv.push_back(make_pair(i, j));
            if (map[i][j])
                total--;
        }
    cout << total - solve(map, 0) << '\n';
    return 0;
}