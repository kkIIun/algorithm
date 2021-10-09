#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll visited[100];

ll func(string s)
{
    memset(visited, 0, sizeof(visited));
    for (ll i = 0; i < s.size(); i++)
    {
        if (visited[s[i] - 'a'] && s[i] != s[i - 1])
            return 0;
        visited[s[i] - 'a'] = 1;
    }
    return 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll TC, ans = 0;
    string s;
    cin >> TC;
    while (TC--)
    {
        cin >> s;
        ans += func(s);
    }
    cout << ans << '\n';

    return 0;
}
