#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll num[10], N, temp;

void Solve(ll start, ll end, ll placeOfNum)
{
    while (start % 10 != 0 && start <= end)
    {
        temp = start;
        while (temp > 0)
        {
            num[temp % 10] += placeOfNum;
            temp /= 10;
        }
        start++;
    }
    if (start > end)
        return;
    while (end % 10 != 9 && end >= start)
    {
        temp = end;
        while (temp > 0)
        {
            num[temp % 10] += placeOfNum;
            temp /= 10;
        }
        end--;
    }

    for (ll i = 0; i < 10; i++)
        num[i] += (end / 10 - start / 10 + 1) * placeOfNum;

    Solve(start / 10, end / 10, placeOfNum * 10);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    Solve(1, N, 1);
    for (ll i = 0; i < 10; i++)
        cout << num[i] << ' ';
    return 0;
}
