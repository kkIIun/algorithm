#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<char>> rec(ll num)
{
    if (num == 1)
        return vector<vector<char>>(1, vector<char>(1, '*'));

    ll n = num / 3;
    vector<vector<char>> r = rec(n);
    vector<vector<char>> c(num, vector<char>(num, ' '));
    for (ll i = 0; i < num; i++)
        for (ll j = 0; j < num; j++)
        {
            if (j >= n && j < n * 2 && i >= n && i < n * 2)
                continue;
            c[i][j] = r[i % n][j % n];
        }
    return c;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    auto ans = rec(n);
    for (ll i = 0; i < ans.size(); i++)
    {
        for (ll j = 0; j < ans.size(); j++)
            cout << ans[i][j];
        cout << '\n';
    }
    return 0;
}
