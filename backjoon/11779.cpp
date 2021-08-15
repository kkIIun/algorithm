#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m, Start, End, dist[1001], route[1001], INF = 987654321;
vector<pair<ll, ll>> graph[1001];
vector<ll> vRoute;

void input()
{
    cin >> n >> m;
    while (m--)
    {
        ll s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back(make_pair(e, c));
    }
    cin >> Start >> End;
}

void dijkstra()
{
    priority_queue<pair<ll, ll>> pq;
    pq.push(make_pair(0, Start));
    dist[Start] = 0;

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
                route[next] = prev;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

void Solve()
{
    input();
    memset(dist, 1000000, sizeof(dist));
    dijkstra();
    cout << dist[End] << endl;
    ll temp = End;
    while (temp)
    {
        vRoute.push_back(temp);
        temp = route[temp];
    }
    cout << vRoute.size() << endl;
    for (ll i = vRoute.size() - 1; i >= 0; i--)
        cout << vRoute[i] << " ";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
