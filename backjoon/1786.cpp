#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> ans;

vector<ll> getPi(string P)
{
    ll pLen = (ll)P.size(), j = 0;
    vector<ll> pi(pLen, 0);
    for (ll i = 1; i < pLen; i++)
    {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<ll> kmp(string T, string P)
{
    vector<ll> ans;
    ll tLen = (ll)T.size(), pLen = (ll)P.size(), j = 0;

    auto pi = getPi(P);

    for (ll i = 0; i < tLen; i++)
    {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1];
        if (T[i] == P[j])
        {
            if (j == pLen - 1)
            {
                ans.push_back(i - j + 1);
                j = pi[j];
            }
            else
                j++;
        }
    }
    return ans;
}

void solve()
{
    string T, P;
    getline(cin, T);
    getline(cin, P);
    auto ans = kmp(T, P);
    cout << (ll)ans.size() << '\n';
    for (ll i = 0; i < (ll)ans.size(); i++)
        cout << ans[i] << ' ';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
