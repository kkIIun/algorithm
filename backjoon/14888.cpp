#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll Max = -1000000000, Min = 1000000000, n;
vector<ll> v;

void dfs(ll idx, ll num, ll oper[])
{

    if (idx == n)
    {
        Max = max(Max, num);
        Min = min(Min, num);
        return;
    }

    for (ll i = 0; i < 4; i++)
        if (oper[i])
        {
            oper[i]--;
            if (i == 0)
                dfs(idx + 1, num + v[idx], oper);
            else if (i == 1)
                dfs(idx + 1, num - v[idx], oper);
            else if (i == 2)
                dfs(idx + 1, num * v[idx], oper);
            else
                dfs(idx + 1, num / v[idx], oper);
            oper[i]++;
        }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll oper[4];
    cin >> n;
    v.assign(n, 0);

    for (ll i = 0; i < n; i++)
        cin >> v[i];
    for (ll i = 0; i < 4; i++)
        cin >> oper[i];

    dfs(1, v[0], oper);
    cout << Max << '\n';
    cout << Min << '\n';
    return 0;
}
