#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, ans = 0;
    map<string, bool> Map;
    cin >> n >> m;
    string s;
    while (n--)
    {
        cin >> s;
        Map[s] = true;
    }
    while (m--)
    {
        cin >> s;
        if (Map.find(s) != Map.end())
            ans++;
    }
    cout << ans << '\n';

    return 0;
}
