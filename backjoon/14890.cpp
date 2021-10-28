#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, ans = 0, l;

bool solve(vector<ll> v)
{
    ll visited[n];
    memset(visited, 0, sizeof(visited));
    for (ll i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            if (v[i] - v[i + 1] != 1)
                return false;
            for (ll j = 0; j < l; j++)
            {
                if (i + 1 + j >= n || v[i + 1] != v[i + 1 + j] || visited[i + 1 + j])
                    return false;
                visited[i + 1 + j] = 1;
            }
        }

        else if (v[i] < v[i + 1])
        {
            if (v[i + 1] - v[i] != 1)
                return false;
            for (ll j = 0; j < l; j++)
            {
                if (i < j || v[i] != v[i - j] || visited[i - j])
                    return false;
                visited[i - j] = 1;
            }
        }
    }

    ans++;
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll in;
    vector<vector<ll>> rows, cols;

    cin >> n >> l;
    rows.assign(n, vector<ll>(n, 0));
    cols.assign(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
        {
            cin >> in;
            rows[i][j] = in;
            cols[j][i] = in;
        }
    for (ll i = 0; i < n; i++)
        solve(rows[i]);

    for (ll i = 0; i < n; i++)
        solve(cols[i]);

    cout << ans << '\n';
    return 0;
}