#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<pair<ll, ll>> v, temp;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}

ll calc(ll start, ll end, ll dist)
{
    temp.assign(v.begin() + start, v.begin() + end + 1);
    sort(temp.begin(), temp.end(), cmp);
    for (ll i = 0; i < temp.size() - 1; i++)
    {
        ll j = i + 1;
        while (j < temp.size() && pow(temp[j].second - temp[i].second, 2) < dist)
        {
            ll dx = pow(temp[j].first - temp[i].first, 2);
            ll dy = pow(temp[j].second - temp[i].second, 2);
            if (dx + dy < dist)
                dist = dx + dy;
            j++;
        }
    }
    return dist;
}

ll find(ll left, ll right)
{
    if (left + 1 == right)
        return pow(v[left].first - v[right].first, 2) + pow(v[left].second - v[right].second, 2);

    ll mid = (left + right) / 2;
    ll Min = min(find(left, mid), find(mid, right));
    ll nL = mid, nR = mid;
    while (1)
    {
        if (nL > left && sqrt(Min) > v[mid].first - v[nL - 1].first)
            nL--;
        else if (nR < right && sqrt(Min) > v[nR + 1].first - v[mid].first)
            nR++;
        else
            break;
    }
    Min = min(Min, calc(nL, nR, Min));
    return Min;
}

void solve()
{
    cin >> n;

    ll x, y;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    cout << find(0, v.size() - 1) << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}