#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
vector<ll> num;
ll arr[10][10], ans[10];

void init()
{
    for (ll i = 0; i < 10; i++)
        arr[1][i] = 1;

    for (ll i = 2; i < 10; i++)
        for (ll j = 0; j < 10; j++)
        {
            if (j != 0)
                arr[i][j] = pow(10, (i - 1));
            else
            {
                arr[i][j] += (i - 2) * 10;
                ll a = 10;
                for (ll k = i - 3; k > 0; k--)
                {
                    arr[i][j] += k * 9 * a;
                    a *= 10;
                }
                arr[i][j] *= 9;
            }
            arr[i][j] += arr[i - 1][j] * 10;
        }
}

void Solve()
{
    cin >> s;
    init();
    reverse(s.begin(), s.end());

    for (ll i = 0; i < s.size(); i++)
        num.push_back(s[i] - '0');

    for (ll i = 0; i < num.size(); i++)
    {
        if (!num[i])
            continue;

        for (ll j = i + 1; j < num.size(); j++)
            ans[num[j]] += num[i] * pow(10, i);

        if (i == 0)
            for (ll j = 0; j <= num[i]; j++)
                ans[j] += 1;

        else
        {
            for (ll j = 0; j < 10; j++)
            {
                if (j < num[i] && j != 0)
                    ans[j] += pow(10, i);

                if (j == 0 && i > 1)
                {
                    ans[j] += (i - 1) * 10;
                    ll a = 10;
                    for (ll k = i - 2; k > 0; k--)
                    {
                        ans[j] += k * 9 * a;
                        a *= 10;
                    }
                    ans[j] *= (num[i] - 1);
                }
                ans[j] += arr[i][j] * num[i];
            }
        }

        ans[0] += i - 1;
        ans[num[i]] += 1;
    }
    for (ll i = 0; i < 10; i++)
        cout << ans[i] << ' ';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
