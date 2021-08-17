#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m, INF = 987654321, ans = INF;
pair<ll, ll> A[2], B[2];
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
ll visited[100][100];

void input()
{
    cin >> n >> m;
    ll x, y;
    for (ll i = 0; i < 2; i++)
    {
        cin >> x >> y;
        A[i] = make_pair(x, y);
    }
    for (ll i = 0; i < 2; i++)
    {
        cin >> x >> y;
        B[i] = make_pair(x, y);
    }
}

void init()
{
    memset(visited, -1, sizeof(visited));
    visited[A[0].second][A[0].first] = 0;
    visited[A[1].second][A[1].first] = 0;
    visited[B[0].second][B[0].first] = 0;
    visited[B[1].second][B[1].first] = 0;
}

void done(pair<ll, ll> pos[2])
{
    vector<tuple<ll, ll, ll>> v;
    v.push_back(make_tuple(pos[1].first, pos[1].second, visited[pos[1].second][pos[1].first]));
    while (get<2>(v.back()) != 0)
    {
        ll x = get<0>(v.back());
        ll y = get<1>(v.back());
        ll cnt = get<2>(v.back());

        for (ll i = 0; i < 4; i++)
        {
            ll nextX = x + dx[i];
            ll nextY = y + dy[i];
            if (nextX < 0 || nextY < 0 || nextX > n || nextY > m || visited[nextY][nextX] != cnt - 1)
                continue;
            v.push_back(make_tuple(nextX, nextY, visited[nextY][nextX]));
            break;
        }
    }
    init();
    for (ll i = 0; i < v.size(); i++)
    {
        ll x = get<0>(v[i]);
        ll y = get<1>(v[i]);
        ll cnt = get<2>(v[i]);
        visited[y][x] = cnt;
    }
}

void bfs(pair<ll, ll> pos[2])
{
    visited[pos[1].second][pos[1].first] = -1;
    queue<tuple<ll, ll, ll>> q;
    q.push(make_tuple(0, pos[0].first, pos[0].second));

    while (!q.empty())
    {
        ll cnt = get<0>(q.front());
        ll x = get<1>(q.front());
        ll y = get<2>(q.front());
        q.pop();
        if (x == pos[1].first && y == pos[1].second)
            return;

        for (ll i = 0; i < 4; i++)
        {
            ll nextX = x + dx[i];
            ll nextY = y + dy[i];

            if (nextX < 0 || nextY < 0 || nextX > n || nextY > m || visited[nextY][nextX] != -1)
                continue;
            visited[nextY][nextX] = cnt + 1;
            q.push(make_tuple(cnt + 1, nextX, nextY));
        }
    }
}

void solve()
{
    input();

    init();
    bfs(A);
    done(A);
    bfs(B);
    visited[B[1].second][B[1].first] = visited[B[1].second][B[1].first] == -1 ? INF : visited[B[1].second][B[1].first];
    ans = visited[A[1].second][A[1].first] + visited[B[1].second][B[1].first];

    init();
    bfs(B);
    done(B);
    bfs(A);
    visited[A[1].second][A[1].first] = visited[A[1].second][A[1].first] == -1 ? INF : visited[A[1].second][A[1].first];
    ans = min(ans, visited[A[1].second][A[1].first] + visited[B[1].second][B[1].first]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    if (ans >= INF)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;
    return 0;
}
