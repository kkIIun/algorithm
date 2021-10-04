#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k, LB[1000001];
vector<ll> fenwickTree;

void init(vector<ll> &v)
{
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 1; j <= LB[i]; j++)
            sum += v[i - j + 1];
        fenwickTree[i] = sum;
    }
}

void update(ll i, ll diff)
{
    while (i <= n)
    {
        fenwickTree[i] += diff;
        i += LB[i];
    }
}

ll sum(ll i)
{
    ll temp = 0;
    while (i > 0)
    {
        temp += fenwickTree[i];
        i -= LB[i];
    }
    return temp;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    fenwickTree.resize(n + 1);

    vector<ll> v(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        LB[i] = i & -i;
        cin >> v[i];
    }
    init(v);

    ll a, b, c;
    for (ll i = 1; i <= m + k; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(b, c - v[b]);
            v[b] = c;
        }
        else
            cout << sum(c) - sum(b - 1) << '\n';
    }
    return 0;
}