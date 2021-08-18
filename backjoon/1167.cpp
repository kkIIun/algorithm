#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll V, visited[100001], ans, maxNode;
vector<pair<ll, ll>> node[100001];

void input()
{
    cin >> V;
    ll n;
    for (ll i = 0; i < V; i++)
    {
        cin >> n;
        ll temp, cost;
        while (1)
        {
            cin >> temp;
            if (temp == -1)
                break;
            cin >> cost;
            node[n].push_back(make_pair(temp, cost));
        }
    }
}

void dfs(ll start, ll sum)
{
    for (ll i = 0; i < node[start].size(); i++)
    {
        ll current = node[start][i].first;
        ll dist = node[start][i].second;
        if (!visited[current])
        {
            visited[current] = 1;
            if (sum + dist > ans)
            {
                ans = sum + dist;
                maxNode = current;
            }
            dfs(current, sum + dist);
            visited[current] = 0;
        }
    }
}

void solve()
{
    visited[1] = 1;
    dfs(1, 0);
    visited[1] = 0;

    visited[maxNode] = 1;
    dfs(maxNode, 0);
    cout << ans << endl;
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
