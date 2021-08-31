#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 987654321;
ll n, d, c, T, *dist;
vector<pair<ll, ll>> *graph;
priority_queue<pair<ll, ll>> pq;

void dijkstra(ll start)
{
    priority_queue<pair<ll, ll>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        ll cost = -pq.top().first;
        ll prev = pq.top().second;
        pq.pop();

        if (dist[prev] < cost)
            continue;

        for (ll i = 0; i < graph[prev].size(); i++)
        {
            ll next = graph[prev][i].first;
            ll nCost = graph[prev][i].second;

            if (dist[next] > cost + nCost)
            {
                dist[next] = cost + nCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

void solve()
{
    cin >> n >> d >> c;
    graph = new vector<pair<ll, ll>>[n + 1];
    ll a, b, s, cnt = 0, ans = 0;

    for (ll i = 0; i < d; i++)
    {
        cin >> a >> b >> s;
        graph[b].push_back(make_pair(a, s));
    }

    dist = new ll[n + 1];
    fill(dist, dist + (n + 1), INF);
    dijkstra(c);
    for (ll i = 1; i <= n; i++)
        if (dist[i] != INF)
        {
            cnt++;
            if (dist[i] > ans)
                ans = dist[i];
        }

    cout << cnt << ' ' << ans << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
        solve();
    return 0;
}
