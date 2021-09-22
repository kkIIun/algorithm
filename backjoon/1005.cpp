#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, End;
vector<vector<ll>> graph;
vector<ll> Time;
vector<ll> ans;
vector<ll> indegree;

void bfs()
{
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        ll cur = q.front();

        q.pop();
        for (auto next : graph[cur])
        {
            ans[next] = max(ans[next], ans[cur] + Time[next]);
            if (--indegree[next] == 0)
                q.push(next);
        }
    }
}

void init()
{
    for (ll i = 1; i <= n; i++)
    {
        cin >> Time[i];
        ans[i] = Time[i];
    }

    ll a, b;
    while (k--)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    cin >> End;
}

void solve()
{
    cin >> n >> k;
    graph.assign(n + 1, vector<ll>());
    indegree.assign(n + 1, 0);
    Time.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    init();
    bfs();
    cout << ans[End] << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll TC;
    cin >> TC;
    while (TC--)
        solve();

    return 0;
}
