#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long ll;

ll v[6][8], n;

void leftRotation(ll idx)
{
    for (ll i = 0; i < 7; i++)
        swap(v[idx][i], v[idx][(i + 1) % 8]);
}

void rightRotation(ll idx)
{
    for (ll i = 7; i > 0; i--)
        swap(v[idx][i], v[idx][(i + 7) % 8]);
}

void solve(ll idx, ll prev, ll dir)
{
    if (idx == 0 || idx == 5)
        return;

    if (v[idx][6] != v[idx - 1][2] && prev != idx - 1)
        solve(idx - 1, idx, dir * -1);

    if (v[idx][2] != v[idx + 1][6] && prev != idx + 1)
        solve(idx + 1, idx, dir * -1);

    if (dir > 0)
        rightRotation(idx);
    else
        leftRotation(idx);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (ll i = 1; i <= 4; i++)
    {
        string s;
        cin >> s;
        for (ll j = 0; j < 8; j++)
            v[i][j] = s[j] - '0';
    }
    cin >> n;
    ll idx, dir;
    while (n--)
    {
        cin >> idx >> dir;
        solve(idx, -1, dir);
    }
    ll ans = 0;
    for (ll i = 1; i <= 4; i++)
        ans += v[i][0] * pow(2, i - 1);
    cout << ans << '\n';
    return 0;
}