#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct info
{
    ll y, x, cnt, dir;
};

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k, l, chg[10001], visited[101][101];
    cin >> n;
    vector<vector<ll>> map(n, vector<ll>(n, 0));
    cin >> k;
    ll x, y;
    while (k--)
    {
        cin >> y >> x;
        map[y - 1][x - 1] = 1;
    }

    cin >> l;
    char c;
    while (l--)
    {
        cin >> x >> c;
        if (c == 'D')
            chg[x] = 1;
        else if (c == 'L')
            chg[x] = -1;
    }
    deque<info> dq;
    dq.push_front({0, 0, 0, 0});
    visited[0][0] = 1;
    while (!dq.empty())
    {
        ll y = dq.front().y;
        ll x = dq.front().x;
        ll cnt = dq.front().cnt;
        ll dir = dq.front().dir;

        if (chg[cnt])
            dir = (4 + dir + chg[cnt]) % 4;
        ll ny = y + dy[dir];
        ll nx = x + dx[dir];

        if (0 > nx || nx > n - 1 || 0 > ny || ny > n - 1 || (visited[ny][nx]))
        {
            cout << cnt + 1 << '\n';
            break;
        }
        visited[ny][nx] = 1;
        if (map[ny][nx])
        {
            map[ny][nx] = 0;
            dq.push_front({ny, nx, cnt + 1, dir});
        }
        else
        {
            dq.pop_front();
            visited[y][x] = 0;
            dq.push_back({ny, nx, cnt + 1, dir});
        }
    }
    return 0;
}