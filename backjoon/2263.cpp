#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, Intree[100001], Posttree[100001], Index[100001];

void input()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> Intree[i];
        Index[Intree[i]] = i;
    }

    for (ll i = 0; i < n; i++)
        cin >> Posttree[i];
}

void solve(ll start, ll end, ll gap)
{
    if (start > end)
        return;

    ll mid = Posttree[end];
    cout << mid << ' ';

    solve(start, Index[mid] - gap - 1, gap);
    solve(Index[mid] - gap, end - 1, gap + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve(0, n - 1, 0);
    return 0;
}
