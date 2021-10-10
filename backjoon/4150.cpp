#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> visited[100001];

vector<ll> rec(ll n)
{
    if (visited[n].size())
        return visited[n];

    vector<ll> a = rec(n - 2);
    vector<ll> b = rec(n - 1);
    a.resize(b.size() + 1, 0);
    ll carry = 0;
    for (ll i = 0; i < b.size(); i++)
    {
        ll temp = b[i];
        b[i] = (carry + a[i] + b[i]) % 10;
        carry = (carry + a[i] + temp) / 10;
    }
    if (carry)
        b.push_back(carry);
    visited[n] = b;
    return b;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    visited[1] = vector<ll>(1, 1);
    visited[2] = vector<ll>(1, 1);
    vector<ll> v = rec(n);
    for (ll i = v.size() - 1; i >= 0; i--)
        cout << v[i];
    return 0;
}
