#include <iostream>
#include <vector>
#include <math.h>

typedef unsigned long long ull;
using namespace std;

ull n, k;

void solve(ull n, ull a, ull b, ull c, ull k)
{
    ull mid = (pow(2, n) - 1) / 2 + 1;
    if (n > 0)
    {
        if (k < mid)
            solve(n - 1, a, c, b, k);
        else if (k == mid)
        {
            cout << a << ' ' << c << '\n';
            return;
        }
        else
            solve(n - 1, b, a, c, k - mid);
    }
}

int main(void)
{
    ull TC;
    cin >> TC;
    while (TC--)
    {
        cin >> n >> k;
        solve(n, 1, 2, 3, k);
    }
    return 0;
}