#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

void solve()
{
    string T;
    while (1)
    {
        cin >> T;
        if (T[0] == '.')
            break;
        ll len = T.size();
        vector<ll> pi = getPi(T);
        if (pi[len - 1] % (len - pi[len - 1]))
            cout << 1 << '\n';
        else
            cout << len / (len - pi[len - 1]) << '\n';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
