#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;
vector<vector<ll>> graph;
vector<ll> score;
vector<ll> indegree;

void bfs()
{
    vector<ll> ans;
    queue<ll> q;

    for (ll i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        ll cur = q.front();
        ans.push_back(cur);
        q.pop();
        for (ll i = 1; i <= n; i++)
            if (graph[cur][i])
                if (--indegree[i] == 0)
                    q.push(i);
    }

    if (ans.size() == n)
        for (ll i = 0; i < n; i++)
            cout << ans[i] << ' ';
    else
        cout << "IMPOSSIBLE";
    cout << '\n';
}

void init()
{
    for (ll i = 1; i <= n; i++)
        cin >> score[i];

    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j < i; j++)
        {
            graph[score[j]][score[i]] = 1;
            indegree[score[i]]++;
        }
}

void solve()
{
    cin >> n;
    graph.assign(n + 1, vector<ll>(n + 1, 0));
    indegree.assign(n + 1, 0);
    score.assign(n + 1, 0);

    init();

    cin >> m;
    ll a, b;
    while (m--)
    {
        cin >> a >> b;
        if (!graph[a][b])
        {
            indegree[a]--;
            indegree[b]++;
            graph[b][a] = 0;
            graph[a][b] = 1;
        }
        else
        {
            indegree[a]++;
            indegree[b]--;
            graph[b][a] = 1;
            graph[a][b] = 0;
        }
    }

    bfs();
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