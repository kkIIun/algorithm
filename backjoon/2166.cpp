#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
pair<ll, ll> pos[100000];
double ans;

void input()
{
    cin >> n;
    ll x, y;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        pos[i] = make_pair(x, y);
    }
}

void solve()
{
    for (ll i = 0; i < n - 1; i++)
    {
        ans += pos[i].first * pos[i + 1].second;
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ans -= pos[i].second * pos[i + 1].first;
    }
    ans += (pos[n - 1].first * pos[0].second - pos[n - 1].second * pos[0].first);
    ans /= 2;
    printf("%.1lf", abs(ans));
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
