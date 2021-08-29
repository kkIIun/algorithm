#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll V, E, ans;
priority_queue<tuple<ll, ll, ll>> pq;
ll parent[1000001], cnt[1000001];

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
    cin >> V >> E;

    for (ll i = 1; i <= V; i++)
    {
        parent[i] = i;
        cnt[i] = 1;
    }

    ll a, b, c;
    while (E--)
    {
        cin >> a >> b >> c;
        pq.push(make_tuple(-c, a, b));
    }
}

void solve()
{
    while (!pq.empty())
    {
        ll cost = -get<0>(pq.top());
        ll a = get<1>(pq.top());
        ll b = get<2>(pq.top());
        pq.pop();

        ll parentA = getParent(a);
        ll parentB = getParent(b);
        if (parentA != parentB)
        {
            ans += cost;
            Union(parentA, parentB);
        }
    }
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
