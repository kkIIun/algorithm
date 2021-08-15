#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, cnt, ncnt;
bool flag = false;
queue<ll> q;
ll visited[100002];

void Solve()
{
    q.push(n);
    visited[n] = 1;
    if (n == k)
        return;
    while (!q.empty())
    {
        ll lq = q.size();
        vector<ll> v;
        while (lq--)
        {
            ll num = q.front();
            q.pop();
            if (2 * num == k || num + 1 == k || num - 1 == k)
            {
                flag = true;
                ncnt++;
            }

            if (2 * num <= 100000 && !visited[2 * num])
            {
                q.push(2 * num);
                v.push_back(2 * num);
            }

            if (num + 1 <= 100000 && !visited[num + 1])
            {
                q.push(num + 1);
                v.push_back(num + 1);
            }

            if (num - 1 >= 0 && !visited[num - 1])
            {
                q.push(num - 1);
                v.push_back(num - 1);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (ll i = 0; i < v.size(); i++)
            visited[v[i]] = 1;
        if (flag)
        {
            cnt++;
            return;
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
    if (!ncnt)
        ncnt++;
    cout << ncnt << endl;
    return 0;
}
