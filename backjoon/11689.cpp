#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, ans;
vector<ll> v;

bool isPrime(ll n)
{
    for (ll i = 2; i <= sqrt(n); i++)
        if (!(n % i))
            return false;
    return true;
}

void solve()
{
    cin >> n;
    ans = n - 1;
    if (isPrime(n))
        return;

    ll temp = n;
    for (ll i = 2; i * i <= temp; i++)
        while (!(temp % i))
        {
            v.push_back(i);
            temp /= i;
        }
    if (temp > 1)
        v.push_back(temp);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ans = n;
    for (ll i = 0; i < v.size(); i++)
    {
        ans /= v[i];
        ans *= (v[i] - 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    ans = ans ? ans : 1;
    cout << ans << '\n';
    return 0;
}
