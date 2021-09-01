#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct planet
{
    ll idx, x, y, z;
};

ll n, parent[100001], cnt[100001], ans = 0;
priority_queue<tuple<ll, ll, ll>> pq;

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

bool compX(planet i, planet j)
{
    if (i.x > j.x)
        return true;
    return false;
}

bool compY(planet i, planet j)
{
    if (i.y > j.y)
        return true;
    return false;
}

bool compZ(planet i, planet j)
{
    if (i.z > j.z)
        return true;
    return false;
}

void input()
{
    cin >> n;
    vector<planet> pos(n);
    for (ll i = 0; i < n; i++)
    {
        parent[i] = i;
        cnt[i] = 1;
        cin >> pos[i].x >> pos[i].y >> pos[i].z;
        pos[i].idx = i;
    }

    ll dist;
    sort(pos.begin(), pos.end(), compX);
    for (ll i = 0; i < n - 1; i++)
    {
        dist = (pos[i].x - pos[i + 1].x);
        pq.push(make_tuple(-dist, pos[i].idx, pos[i + 1].idx));
    }
    sort(pos.begin(), pos.end(), compY);
    for (ll i = 0; i < n - 1; i++)
    {
        dist = (pos[i].y - pos[i + 1].y);
        pq.push(make_tuple(-dist, pos[i].idx, pos[i + 1].idx));
    }
    sort(pos.begin(), pos.end(), compZ);
    for (ll i = 0; i < n - 1; i++)
    {
        dist = (pos[i].z - pos[i + 1].z);
        pq.push(make_tuple(-dist, pos[i].idx, pos[i + 1].idx));
    }
}

void solve()
{
    while (!pq.empty())
    {
        ll dist = -get<0>(pq.top());
        ll a = get<1>(pq.top());
        ll b = get<2>(pq.top());
        pq.pop();

        ll parentA = getParent(a);
        ll parentB = getParent(b);
        if (parentA != parentB)
        {
            ans += dist;
            Union(parentA, parentB);
        }
    }
    cout << ans << '\n';
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
