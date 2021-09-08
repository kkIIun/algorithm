#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, arr[1000000];
stack<ll> stk;
string ans = "";

void solve()
{
    ll j = 0;
    for (ll i = 1; i <= n; i++)
    {
        stk.push(i);
        ans += "+\n";
        while (!stk.empty() && stk.top() == arr[j])
        {
            stk.pop();
            ans += "-\n";
            j++;
        }
    }
    if (!stk.empty())
        cout << "NO" << '\n';
    else
        cout << ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    solve();
    return 0;
}
