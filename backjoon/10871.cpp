#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, x;
vector<ll> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ll num;
    for (ll i = 0; i < n; i++)
    {
        cin >> num;
        if (num < x)
            cout << num << ' ';
    }

    return 0;
}
