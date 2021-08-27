#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll g, p, parent[100001], cnt, n;
bool flag;

ll getParent(ll a)
{
    if (parent[a] == a)
        return a;
    parent[a] = getParent(parent[a]);
    return parent[a];
}

void solve()
{
    cin >> g >> p;
    for (ll i = 1; i <= g; i++)
        parent[i] = i;
    while (p--)
    {
        cin >> n;
        if (!flag)
        {
            n = getParent(n);
            if (!n)
                flag = true;
            else
            {
                parent[n] = (n - 1);
                cnt++;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    cout << cnt << '\n';
    return 0;
}
