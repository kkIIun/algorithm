#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<pair<ll, ll>> v;

ll calc(ll start, ll end, ll mid)
{
    ll result = 800000001;
    for (ll i = start; i <= mid; i++)
        for (ll j = mid + 1; j <= end; j++)
        {
            ll temp = pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2);
            if (result > temp)
                result = temp;
        }
    return result;
}

ll find(ll left, ll right)
{
    if (left + 1 == right)
        return pow(v[left].first - v[right].first, 2) + pow(v[left].second - v[right].second, 2);

    ll mid = (left + right) / 2;
    ll Min = min(find(left, mid), find(mid, right));
    ll nL = mid, nR = mid + 1;
    while (1)
    {
        if (nL > left && sqrt(Min) > v[mid].first - v[nL].first)
            nL--;
        else if (nR < right && sqrt(Min) > v[nR].first - v[mid].first)
            nR++;
        else
            break;
    }
    Min = min(Min, calc(nL, nR, mid));
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