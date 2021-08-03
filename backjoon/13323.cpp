#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

priority_queue<ll> pq;
ll n;

void Solve()
{
    cin >> n;
    ll num, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> num;
        num -= i;
        pq.push(num);
        if (!pq.empty() && pq.top() > num)
        {
            ans += pq.top() - num;
            pq.pop();
            pq.push(num);
        }
    }
    cout << ans << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
