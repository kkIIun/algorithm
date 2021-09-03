
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, w[10001], visited[10001], dp[10001][2];
vector<ll> e[10001], ans;

void input()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> w[i];
    ll start, end;
    for (ll i = 1; i < n; i++)
    {
        cin >> start >> end;
        e[start].push_back(end);
        e[end].push_back(start);
    }
}

void dfs(ll start)
{
    for (ll next : e[start])
    {
        if (visited[next])
            continue;
        visited[next] = 1;
        dfs(next);
        dp[start][1] += dp[next][0];
        dp[start][0] += max(dp[next][1], dp[next][0]);
    }
    dp[start][1] += w[start];
}

void solve()
{
    visited[1] = 1;
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
