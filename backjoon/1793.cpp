#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits>
#include <set>
#include <string>
#include <stdio.h>
using namespace std;

typedef unsigned long long ll;
string dp[251];
ll n;

string sumNum(string num1, string num2)
{
    long long sum = 0;

    string result;

    while (!num1.empty() || !num2.empty() || sum)

    {

        if (!num1.empty())

        {

            sum += num1.back() - '0';

            num1.pop_back();
        }

        if (!num2.empty())

        {

            sum += num2.back() - '0';

            num2.pop_back();
        }

        result.push_back((sum % 10) + '0');

        sum /= 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

void Solve()
{
    dp[0] = '1';
    dp[1] = '1';
    for (ll i = 2; i <= 250; i++)
        dp[i] = sumNum(sumNum(dp[i - 2], dp[i - 2]), dp[i - 1]);

    while (~scanf("%d", &n))
    {
        cout << dp[n] << endl;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
