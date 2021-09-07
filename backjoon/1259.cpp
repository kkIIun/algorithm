#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;

void solve()
{
    for (ll i = 0; i < s.size(); i++)
        if (s[i] != s[s.size() - 1 - i])
        {
            cout << "no" << '\n';
            return;
        }

    cout << "yes" << '\n';
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        cin >> s;
        if (s == "0")
            break;
        solve();
    }
    return 0;
}
