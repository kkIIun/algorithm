#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, cnt = 1;

void bfs()
{
    queue<ll> q;
    vector<ll> next;
    q.push(n);
    while (!q.empty())
    {
        while (!q.empty())
        {
            ll n = q.front();
            q.pop();
            if (n == m)
            {
                cout << cnt << '\n';
                return;
            }
            if (n * 2 <= m)
                next.push_back(n * 2);
            if (n * 10 + 1 <= m)
                next.push_back(n * 10 + 1);
        }

        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());

        while (!next.empty())
        {
            q.push(next.back());
            next.pop_back();
        }
        cnt++;
    }
    cout << -1 << '\n';
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bfs();
    return 0;
}
