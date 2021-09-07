#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b, c;

ll pow(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll num = pow(a, b / 2);
    ll temp = (num * num) % c;

    if (b % 2)
        return (temp * a) % c;
    else
        return temp;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    a %= c;
    cout << pow(a, b) % c;
    return 0;
}
