#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;

ll DFA[3][1001];

ll kmp(string pattern)
{
    ll result = 1, X = 0, n = pattern.size();
    memset(DFA, 0, sizeof(DFA));
    DFA[pattern[0] - 'A'][0] = 1;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < 3; j++)
            DFA[j][i] = DFA[j][X];
        DFA[pattern[i] - 'A'][i] = i + 1;
        X = DFA[pattern[i] - 'A'][X];
        for (ll j = 0; j < 3; j++)
            if (DFA[j][i])
                result++;
    }
    for (ll j = 0; j < 3; j++)
    {
        DFA[j][n] = DFA[j][X];
        if (DFA[j][n])
            result++;
    }
    return result;
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
        cout << kmp(pattern) << ' ';
        ll j = 0;
        for (ll i = 0; i < n; i++)
        {
            j = DFA[text[i] - 'A'][j];
            if (j == m)
                ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}