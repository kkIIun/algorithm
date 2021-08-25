#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, A[20001], B[20001], C[20001], resultNum = -1;
ll cumSum(ll mid)
{
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
        if (mid >= A[i])
            sum += (min(mid, C[i]) - A[i]) / B[i] + 1;
    return sum;
}

void solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> A[i] >> C[i] >> B[i];
    ll lo = *min_element(A + 1, A + n + 1);
    ll hi = *max_element(C + 1, C + n + 1);

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll sum = cumSum(mid);

        if (sum % 2)
        {
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    if (resultNum == -1)
        cout << "NOTHING" << '\n';
    else
        cout << resultNum << ' ' << cumSum(resultNum) - cumSum(resultNum - 1) << '\n';
    return 0;
}
