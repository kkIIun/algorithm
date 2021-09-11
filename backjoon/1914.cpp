#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void recursive(ll n, ll start, ll mid, ll end)
{
    if (n == 0)
        return;
    recursive(n - 1, start, end, mid);
    cout << start << ' ' << end << '\n';
    recursive(n - 1, mid, start, end);
}

vector<ll> pow(ll n)
{
    ll num, carry = 0;
    vector<ll> result;
    if (n == 1)
    {
        result.push_back(2);
        return result;
    }

    result = pow(n - 1);
    for (ll i = 0; i < result.size(); i++)
    {
        result[i] = result[i] * 2 + carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    if (carry)
        result.push_back(carry);
    return result;
}

void solve()
{
    ll n;
    cin >> n;

    vector<ll> ans = pow(n);
    ans[0] = ans[0] - 1;
    for (ll i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << '\n';
    if (n <= 20)
        recursive(n, 1, 2, 3);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}