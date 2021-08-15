#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, cnt;
deque<ll> dq;
map<ll, bool> visited;

void Solve()
{
    dq.push_back(n);
    visited[n] = true;
    while (!dq.empty())
    {
        ll lq = dq.size();
        while (lq--)
        {
            ll num = dq.front();
            dq.pop_front();
            if (num == k)
                return;
            if (2 * num <= 100000 && visited.find(2 * num) == visited.end())
            {
                dq.push_front(2 * num);
                lq++;
                visited[2 * num] = true;
            }
            if (num + 1 <= 100000 && visited.find(num + 1) == visited.end())
            {
                dq.push_back(num + 1);
                visited[num + 1] = true;
            }
            if (num - 1 >= 0 && visited.find(num - 1) == visited.end())
            {
                dq.push_back(num - 1);
                visited[num - 1] = true;
            }
        }
        cnt++;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    Solve();
    cout << cnt << endl;
    return 0;
}
