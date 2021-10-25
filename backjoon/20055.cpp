#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define Max 200

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k, dur[Max], CB[Max], robot[Max], cnt = 0, ans = 0;
    cin >> n >> k;
    for (ll i = 0; i < 2 * n; i++)
    {
        CB[i] = i;
        robot[i] = 0;
        cin >> dur[i];
    }

    while (cnt < k)
    {
        ans++;

        // move
        ll i = 2 * n - 1;
        while (i > 0)
        {
            swap(CB[i], CB[i - 1]);
            i--;
        }

        // robot remove
        if (robot[CB[n - 1]])
            robot[CB[n - 1]] = 0;

        // robot move
        i = n - 1;
        while (i > 0)
        {
            if (dur[CB[i]] && !robot[CB[i]] && robot[CB[i - 1]])
            {
                swap(robot[CB[i]], robot[CB[i - 1]]);
                if (--dur[CB[i]] == 0)
                    cnt++;
            }
            i--;
        }

        // robot remove
        if (robot[CB[n - 1]])
            robot[CB[n - 1]] = 0;

        // push
        if (dur[CB[0]])
        {
            robot[CB[0]] = 1;
            if (--dur[CB[0]] == 0)
                cnt++;
        }
    }

    cout << ans << '\n';
}