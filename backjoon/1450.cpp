#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, c, ans, visited[32768];
vector<ll> v;

vector<ll> splitArr(ll left, ll len)
{
    vector<ll> result;
    for (ll i = 0; i < (1 << len); i++)
    {
        ll sum = 0;
        for (ll j = 0; j < len; j++)
            if ((1 << j) & i)
                sum += v[left + j];
        result.push_back(sum);
    }
    return result;
}

ll upperBound(ll target, vector<ll> &g2)
{
    if (target < g2[0])
        return 0;

    ll left = 0, right = g2.size() - 1;
    while (left < right)
    {
        ll mid = ceil((left + right) / 2.0);
        if (target >= g2[mid])
            left = mid;
        else
            right = mid - 1;
    }
    return left + 1;
}

void solve()
{
    cin >> n >> c;
    v.assign(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    vector<ll> g1 = splitArr(0, n / 2);
    vector<ll> g2 = splitArr(n / 2, ceil(n / 2.0));
    sort(g2.begin(), g2.end());
    for (ll i = 0; i < g1.size(); i++)
        ans += upperBound(c - g1[i], g2);

    cout << ans << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
