#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, End;
vector<vector<ll>> graph;
vector<ll> indegree;

void bfs()
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 1; i <= n; i++)
        if (!indegree[i])
            pq.push(i);

    while (!pq.empty())
    {
        ll cur = pq.top();
        cout << cur << ' ';
        pq.pop();
        for (auto next : graph[cur])
            if (--indegree[next] == 0)
                pq.push(next);
    }
}

void init()
{
    ll a, b;
    while (k--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
}

void solve()
{
    cin >> n >> k;
    graph.assign(n + 1, vector<ll>());
    indegree.assign(n + 1, 0);
    init();
    bfs();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
