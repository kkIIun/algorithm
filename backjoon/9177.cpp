#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, aL, bL, cL;
string a, b, c;
bool flag;

bool check()
{
    vector<int> alp(27, 0);
    for (ll i = 0; i < aL; i++)
        alp[a[i] - 'a']++;
    for (ll i = 0; i < bL; i++)
        alp[b[i] - 'a']++;
    for (ll i = 0; i < cL; i++)
        alp[c[i] - 'a']--;
    for (ll i = 0; i < 26; i++)
        if (alp[i] != 0)
            return false;
    return true;
}

void dfs(ll fir, ll sec, ll thi)
{
    if (flag)
        return;
    if (thi == cL)
    {
        flag = true;
        return;
    }
    if (fir < aL && a[fir] == c[thi])
        dfs(fir + 1, sec, thi + 1);

    if (sec < bL && b[sec] == c[thi])
        dfs(fir, sec + 1, thi + 1);
}

void Solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        flag = false;
        cin >> a >> b >> c;
        aL = a.length();
        bL = b.length();
        cL = c.length();
        if (check())
            dfs(0, 0, 0);
        if (flag)
            cout << "Data set " << i << ": yes" << endl;
        else
            cout << "Data set " << i << ": no" << endl;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
