#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, visited[9];

void dfs(string ans, ll depth, ll prev)
{
    if (depth == m)
    {
        cout << ans << '\n';
        return;
    }

    for (ll i = 1; i <= n; i++)
        if (!visited[i] && prev < i)
        {
            visited[i] = 1;
            dfs(ans + ' ' + to_string(i), depth + 1, i);
            visited[i] = 0;
        }
}

void solve()
{
    cin >> n >> m;

    for (ll i = 1; i <= n - m + 1; i++)
    {
        visited[i] = 1;
        dfs(to_string(i), 1, 0);
        for (ll j = i + 1; j <= n; j++)
            visited[j] = 0;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
