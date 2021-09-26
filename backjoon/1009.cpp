#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll Pow(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll temp = Pow(a, b / 2) % 10;
    temp = (temp * temp) % 10;
    if (b % 2)
        return (temp * a) % 10;
    else
        return temp;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        ll result = Pow(a, b);
        if (result != 0)
            cout << result << '\n';
        else
            cout << 10 << '\n';
    }
    return 0;
}
