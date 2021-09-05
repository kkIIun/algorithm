#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll parent[3001], cnt[3001], n, group, maxCnt, visited[3001];

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

ll ccw(pair<ll, ll> pos1, pair<ll, ll> pos2, pair<ll, ll> pos3)
{
    ll temp = (pos2.first - pos1.first) * (pos3.second - pos1.second) - (pos2.second - pos1.second) * (pos3.first - pos1.first);
    if (temp < 0)
        return -1;
    else if (temp == 0)
        return 0;
    else
        return 1;
}

bool cross(pair<ll, ll> pos1, pair<ll, ll> pos2, pair<ll, ll> pos3, pair<ll, ll> pos4)
{
    ll ccw1 = ccw(pos1, pos2, pos3) * ccw(pos1, pos2, pos4);
    ll ccw2 = ccw(pos3, pos4, pos1) * ccw(pos3, pos4, pos2);
    if (ccw1 <= 0 && ccw2 <= 0)
    {
        if (ccw1 == 0 && ccw2 == 0)
        {

            if (pos1 > pos2)
                swap(pos1, pos2);

            if (pos3 > pos4)
                swap(pos3, pos4);

            if (pos1 <= pos4 && pos3 <= pos2)
                return true;
            else
                return false;
        }
        else
            return true;
    }

    else
        return false;
}

void solve()
{
    cin >> n;
    ll x1, y1, x2, y2;
    vector<pair<pair<ll, ll>, pair<ll, ll>>> line;
    for (ll i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        line.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
        parent[i] = i;
        cnt[i] = 1;
    }

    for (ll i = 0; i < n - 1; i++)
        for (ll j = i + 1; j < n; j++)
        {
            ll parentI = getParent(i);
            ll parentJ = getParent(j);
            if (parentI != parentJ && cross(line[i].first, line[i].second, line[j].first, line[j].second))
                Union(parentI, parentJ);
        }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    for (ll i = 0; i < n; i++)
    {
        ll parentI = getParent(i);
        if (!visited[parentI])
        {
            visited[parentI] = 1;
            group++;
            if (cnt[parentI] > maxCnt)
                maxCnt = cnt[parentI];
        }
    }
    cout << group << '\n';
    cout << maxCnt << '\n';
    return 0;
}
