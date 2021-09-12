#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll len = 1;

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

bool kmp(string T, string P)
{
    ll tLen = (ll)T.size(), pLen = (ll)P.size(), j = 0;
    ll result = 0;
    auto pi = getPi(P);

    for (ll i = 0; i < tLen; i++)
    {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1];
        if (T[i] == P[j])
        {
            if (j == pLen - 1)
            {
                result++;
                j = pi[j];
                if (result >= 2)
                    return true;
            }

            else
                j++;
        }
    }
    return false;
}

void solve()
{
    string T;
    getline(cin, T);
    for (ll i = 0; i <= T.size() - len;)
    {
        string S = "";
        S += T[i];
        for (ll j = 1; j < len; j++)
            S += T[i + j];

        if (kmp(T, S))
            len++;
        else
            i++;
    }
    cout << len - 1 << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
