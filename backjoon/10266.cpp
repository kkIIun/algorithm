#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<ll> T1, T2;

vector<ll> getPi(string P)
{
    vector<ll> pi;
    ll len = P.size(), j = 0;
    pi.assign(len, 0);
    for (ll i = 1; i < len; i++)
    {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            pi[i] = ++j;
    }
    return pi;
}

bool kmp(string T, string P)
{
    auto pi = getPi(P);
    ll len = T.size(), j = 0;
    for (ll i = 0; i < len; i++)
    {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1];
        if (T[i] == P[j])
        {
            if (j == P.size() - 1)
                return true;
            else
                j++;
        }
    }
    return false;
}

string newStr(bool flag)
{
    vector<ll> v;
    string result = "";
    ll temp;
    v.assign(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (ll i = 0; i < n; i++)
    {
        if (i == n - 1)
            temp = v[n - 1] - v[0];
        else
            temp = v[i + 1] - v[i];
        result += to_string(temp > 180000 ? 360000 - temp : temp);
    }
    if (flag)
        for (ll i = 0; i < n - 1; i++)
        {
            temp = v[i + 1] - v[i];
            result += to_string(temp > 180000 ? 360000 - temp : temp);
        }
    return result;
}

void solve()
{
    cin >> n;
    auto T1 = newStr(true);
    auto T2 = newStr(false);
    if (kmp(T1, T2))
        cout << "possible" << '\n';
    else
        cout << "impossible" << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}