#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, parent[1000001], cnt[1000001];
double ans;
priority_queue<tuple<double, double, double>> pq;
pair<double, double> pos[101];

ll getParent(ll a)
{
    if (parent[a] == a)
        return a;
    return getParent(parent[a]);
}

void Union(ll a, ll b)
{
    if (cnt[a] < cnt[b])
        swap(a, b);
    if (a != b)
    {
        parent[b] = a;
        cnt[a] += cnt[b];
    }
}

void input()
{
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        parent[i] = i;
        cnt[i] = 1;
    }

    double x, y;
    for (ll i = 1; i <= n; i++)
    {
        cin >> x >> y;
        pos[i] = make_pair(x, y);
    }

    double dist;
    for (ll i = 1; i < n; i++)
        for (ll j = i + 1; j <= n; j++)
        {
            dist = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
            pq.push(make_tuple(-dist, i, j));
        }
}

void solve()
{
    while (!pq.empty())
    {
        double dist = -get<0>(pq.top());
        double a = get<1>(pq.top());
        double b = get<2>(pq.top());
        pq.pop();

        ll parentA = getParent(a);
        ll parentB = getParent(b);
        if (parentA != parentB)
        {
            ans += dist;
            Union(parentA, parentB);
        }
    }
    printf("%lf", ans);
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
