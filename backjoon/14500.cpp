#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll v[500][500];

struct pos
{
    ll y, x;
};

ll calc(ll i, ll j, pos a, pos b, pos c, pos d)
{
    return v[i + a.y][j + a.x] + v[i + b.y][j + b.x] + v[i + c.y][j + c.x] + v[i + d.y][j + d.x];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, Max = 0;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> v[i][j];

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m - 3; j++)
            Max = max(Max, calc(i, j, {0, 0}, {0, 1}, {0, 2}, {0, 3}));
    for (ll i = 0; i < n - 3; i++)
        for (ll j = 0; j < m; j++)
            Max = max(Max, calc(i, j, {0, 0}, {1, 0}, {2, 0}, {3, 0}));
    for (ll i = 0; i < n - 1; i++)
        for (ll j = 0; j < m - 1; j++)
            Max = max(Max, calc(i, j, {0, 0}, {0, 1}, {1, 0}, {1, 1}));
    for (ll i = 0; i < n - 2; i++)
        for (ll j = 0; j < m - 1; j++)
            Max = max({Max,
                       calc(i, j, {0, 0}, {1, 0}, {2, 0}, {2, 1}),
                       calc(i, j, {0, 0}, {0, 1}, {1, 0}, {2, 0}),
                       calc(i, j, {0, 0}, {0, 1}, {1, 1}, {2, 1}),
                       calc(i, j, {0, 1}, {1, 1}, {2, 1}, {2, 0}),
                       calc(i, j, {0, 0}, {1, 0}, {1, 1}, {2, 1}),
                       calc(i, j, {0, 1}, {1, 1}, {1, 0}, {2, 0}),
                       calc(i, j, {0, 0}, {1, 0}, {1, 1}, {2, 0}),
                       calc(i, j, {0, 1}, {1, 1}, {1, 0}, {2, 1})});
    for (ll i = 0; i < n - 1; i++)
        for (ll j = 0; j < m - 2; j++)
            Max = max({Max,
                       calc(i, j, {0, 0}, {1, 0}, {0, 1}, {0, 2}),
                       calc(i, j, {0, 0}, {1, 2}, {0, 1}, {0, 2}),
                       calc(i, j, {1, 0}, {1, 1}, {1, 2}, {0, 2}),
                       calc(i, j, {1, 0}, {1, 1}, {1, 2}, {0, 0}),
                       calc(i, j, {0, 0}, {1, 1}, {0, 1}, {0, 2}),
                       calc(i, j, {1, 0}, {0, 1}, {1, 1}, {1, 2}),
                       calc(i, j, {1, 0}, {1, 1}, {0, 1}, {0, 2}),
                       calc(i, j, {0, 0}, {0, 1}, {1, 1}, {1, 2})});
    cout << Max << '\n';
    return 0;
}