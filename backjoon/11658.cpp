#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, k, LB[1000001], ans;
vector<vector<ll>> fenwickTree;

void init(ll idx, vector<ll> &v)
{
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 1; j <= LB[i]; j++)
            sum += v[i - j + 1];
        fenwickTree[idx][i] = sum;
    }
}

void update(ll idx, ll i, ll diff)
{
    while (i <= n)
    {
        fenwickTree[idx][i] += diff;
        i += LB[i];
    }
}

ll sum(ll idx, ll i)
{
    ll result = 0;
    while (i > 0)
    {
        result += fenwickTree[idx][i];
        i -= LB[i];
    }
    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fenwickTree.assign(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> map(n + 1, vector<ll>(n + 1, 0));

    for (ll i = 1; i <= n; i++)
        LB[i] = i & -i;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
            cin >> map[i][j];

        vector<ll> v(n + 1, 0);
        for (ll k = 1; k <= LB[i]; k++)
            for (ll j = 1; j <= n; j++)
                v[j] += map[i - k + 1][j];

        init(i, v);
    }

    ll w, x1, y1, x2, y2, cost;
    for (ll i = 1; i <= m + k; i++)
    {
        cin >> w >> x1 >> y1;
        if (w == 0)
        {
            cin >> cost;
            ll temp = x1;
            while (temp <= n)
            {
                update(temp, y1, cost - map[x1][y1]);
                temp += LB[temp];
            }
            map[x1][y1] = cost;
        }
        else
        {
            cin >> x2 >> y2;
            ans = 0;
            while (x2 > 0)
            {
                ans += sum(x2, y2) - sum(x2, y1 - 1);
                x2 -= LB[x2];
            }

            x1--;
            while (x1 > 0)
            {
                ans -= sum(x1, y2) - sum(x1, y1 - 1);
                x1 -= LB[x1];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}