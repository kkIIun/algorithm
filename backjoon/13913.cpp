#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, cnt, dp[100001];
queue<ll> q;
map<ll, bool> visited;

void func(ll num)
{
    if (dp[num] == num)
    {
        cout << num << ' ';
        return;
    }
    func(dp[num]);
    cout << num << ' ';
}

void Solve()
{
    for (ll i = 0; i <= 100000; i++)
        dp[i] = i;
    q.push(n);
    visited[n] = true;
    while (!q.empty())
    {
        ll lq = q.size();
        while (lq--)
        {
            ll num = q.front();
            q.pop();
            if (num == k)
                return;
            if (2 * num <= 100000 && visited.find(2 * num) == visited.end())
            {
                q.push(2 * num);
                visited[2 * num] = true;
                dp[2 * num] = num;
            }
            if (num + 1 <= 100000 && visited.find(num + 1) == visited.end())
            {
                q.push(num + 1);
                visited[num + 1] = true;
                dp[num + 1] = num;
            }
            if (num - 1 >= 0 && visited.find(num - 1) == visited.end())
            {
                q.push(num - 1);
                visited[num - 1] = true;
                dp[num - 1] = num;
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
    func(k);
    return 0;
}
