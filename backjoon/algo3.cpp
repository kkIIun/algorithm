#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;
using namespace std;

ll ans = 0;

void solve()
{
    ll In, n;
    cin >> n;
    priority_queue<ll> maxQ, minQ;
    for (ll i = 1; i <= n; i++)
    {
        cin >> In;
        if (maxQ.empty())
        {
            maxQ.push(In);
            ans += In;
        }
        else if (minQ.empty())
        {
            ll temp = maxQ.top();
            if (temp > In)
            {
                maxQ.pop();
                maxQ.push(In);
                minQ.push(-temp);
            }
            else
                minQ.push(-In);
            ans += (In + temp) / 2;
        }
        else
        {
            if (i % 2)
            {
                ll minT = -minQ.top();
                if (minT < In)
                {
                    minQ.pop();
                    maxQ.push(minT);
                    minQ.push(-In);
                }
                else
                    maxQ.push(In);
                ans += maxQ.top();
            }
            else
            {
                ll maxT = maxQ.top();
                if (maxT > In)
                {
                    maxQ.pop();
                    maxQ.push(In);
                    minQ.push(-maxT);
                }
                else
                    minQ.push(-In);
                ans += (maxQ.top() - minQ.top()) / 2;
            }
        }
    }
}

int main(void)
{
    ll TC;
    cin >> TC;
    while (TC--)
    {
        ans = 0;
        solve();
        cout << ans % 10 << '\n';
    }
    return 0;
}