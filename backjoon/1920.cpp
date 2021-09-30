#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;
vector<ll> v;

bool bs(ll num)
{
    ll start = 0;
    ll end = n - 1;
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (v[mid] < num)
            start = mid + 1;
        else if (v[mid] == num)
            return true;
        else
            end = mid - 1;
    }
    return false;
}

void solve()
{
    cin >> n;
    v.assign(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    cin >> m;
    ll temp;
    while (m--)
    {
        cin >> temp;
        cout << bs(temp) << '\n';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}