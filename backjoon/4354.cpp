#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> v;
string T;

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
    string P = T;
    ll ans = 0;
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    for (ll i = 0; i < P.size(); i++)
    {
        auto v = kmp(T, P[i]);
        vector<ll> arr;
        arr.assign(v.size(), 0);
        for (ll i = 0; i < v.size() - 2; i++)
            if (v[i + 1] - v[i] == v[i + 2] - v[i + 1])
            {
                for (ll j = 0; j < v[i + 1] - v[i]; j++)
                    if (T[v[i] + j] != T[v[i + 1] + j])
                        break;
                    else if (j == v[i + 1] - v[i] - 1)
                        arr[i + 1] = arr[i] + 1;
            }
        ans = max(ans, *max_element(arr.cbegin(), arr.cend()));
    }
    cout << ans + 1 << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        getline(cin, T);
        if (T[0] == '.')
            break;
        solve();
    }
    return 0;
}
