#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll t, f, Xcnt, Ocnt, Xsuc, Osuc;
string arr;

void check()
{
    for (ll row = 0; row < 3; row++)
    {
        if (arr[0 + 3 * row] == arr[1 + 3 * row] && arr[1 + 3 * row] == arr[2 + 3 * row] && arr[0 + 3 * row] == 'X')
            Xsuc++;
        if (arr[0 + 3 * row] == arr[1 + 3 * row] && arr[1 + 3 * row] == arr[2 + 3 * row] && arr[0 + 3 * row] == 'O')
            Osuc++;
    }
    for (ll col = 0; col < 3; col++)
    {
        if (arr[col] == arr[col + 3] && arr[col + 3] == arr[col + 6] && arr[col] == 'X')
            Xsuc++;
        if (arr[col] == arr[col + 3] && arr[col + 3] == arr[col + 6] && arr[col] == 'O')
            Osuc++;
    }
    if (arr[0] == arr[4] && arr[4] == arr[8] && arr[0] == 'X')
        Xsuc++;
    if (arr[0] == arr[4] && arr[4] == arr[8] && arr[0] == 'O')
        Osuc++;
    if (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] == 'X')
        Xsuc++;
    if (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] == 'O')
        Osuc++;
}

void solve()
{
    while (1)
    {
        cin >> arr;
        Ocnt = 0;
        Osuc = 0;
        Xcnt = 0;
        Xsuc = 0;

        if (arr == "end")
            return;
        for (ll i = 0; i < 9; i++)
        {
            if (arr[i] == 'O')
                Ocnt++;
            if (arr[i] == 'X')
                Xcnt++;
        }
        if (Ocnt > Xcnt)
        {
            cout << "invalid" << '\n';
            continue;
        }
        check();
        if (!Xsuc && !Osuc && Xcnt + Ocnt == 9)
        {
            cout << "valid" << '\n';
            continue;
        }
        if (Xsuc && !Osuc && Ocnt + 1 == Xcnt)
        {
            cout << "valid" << '\n';
            continue;
        }
        if (!Xsuc && Osuc && Ocnt == Xcnt)
        {
            cout << "valid" << '\n';
            continue;
        }
        cout << "invalid" << '\n';
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
