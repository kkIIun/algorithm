#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll;
vector<ll> V;
ll Arr[1000001];
ll N;

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        if (V.size() == 0 || V[V.size() - 1] < Arr[i])

            V.push_back(Arr[i]);

        else
        {
            int Left = 0;
            int Right = V.size() - 1;
            while (Left < Right)
            {
                int Mid = (Left + Right) / 2;
                if (V[Mid] >= Arr[i])
                    Right = Mid;
                else
                    Left = Mid + 1;
            }
            V[Left] = Arr[i];
        }
    }
    cout << V.size() << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (ll i = 1; i <= N; i++)
        cin >> Arr[i];
    Solution();
    return 0;
}
