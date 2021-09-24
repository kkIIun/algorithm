#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k;
vector<vector<ll>> graph;
vector<ll> indegree, parent, cnt;

ll getParent(ll a)
{
    if (parent[a] == a)
        return a;
    parent[a] = getParent(parent[a]);
    return parent[a];
}

void Union(ll a, ll b)
{
    a = getParent(a);
    b = getParent(b);
    if (cnt[a] < cnt[b])
        swap(a, b);
    if (a != b)
    {
        parent[b] = a;
        cnt[a] += cnt[b];
    }
}

void bfs()
{
    queue<ll> q;
    for (ll i = 0; i < n; i++)
        if (!indegree[i])
            q.push(i);

    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        for (auto next : graph[cur])
            if (--indegree[next] == 0)
                q.push(next);
    }
}

void init()
{
    for (ll i = 0; i < n; i++)
    {
        parent[i] = i;
        cnt[i] = 0;
    }

    vector<pair<ll, ll>> temp;
    ll a, b;
    char ch;
    while (k--)
    {
        cin >> a >> ch >> b;
        if (ch == '>')
            temp.push_back(make_pair(a, b));

        else
            Union(a, b);
    }

    for (ll i = 0; i < temp.size(); i++)
    {
        ll fP = getParent(temp[i].first);
        ll eP = getParent(temp[i].second);
        graph[fP].push_back(eP);
        indegree[eP]++;
    }
}

void solve()
{
    cin >> n >> k;
    graph.assign(n + 1, vector<ll>());
    indegree.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    init();
    bfs();
    for (ll i = 0; i < n; i++)
        if (indegree[i])
        {
            cout << "inconsistent";
            return;
        }
    cout << "consistent";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
