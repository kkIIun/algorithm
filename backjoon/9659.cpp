#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n % 2)
        cout << "SK";
    else
        cout << "CY";
    return 0;
}
