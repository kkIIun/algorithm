#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

vector<ll> kmp(string pattern)
{
    ll n = pattern.size();
    ll j = 0;
    vector<ll> fail(n, 0);
    for (ll i = 1; i < n; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = fail[j - 1];
        if (pattern[i] == pattern[j])
            fail[i] = ++j;
    }
    return fail;
}

int main(void)
{
    ll test;
    cin >> test;
    while (test--)
    {
        string text, pattern;
        ll ans = 0;
        cin >> pattern >> text;
        ll n = text.size();
        ll m = pattern.size();
        vector<ll> fail = kmp(pattern);

        for (ll i = 0; i < pattern.length(); i++)
            cout << fail[i] << ' ';
        cout << '\n';

        ll j = 0;
        for (ll i = 0; i < n; i++)
        {
            while (j > 0 && text[i] != pattern[j])
                j = fail[j - 1];
            if (text[i] == pattern[j])
                if (j == m - 1)
                {
                    ans++;
                    j = fail[j];
                }
                else
                    j++;
        }
        cout << ans << '\n';
    }
    return 0;
}