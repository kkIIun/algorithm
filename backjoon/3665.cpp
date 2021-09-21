#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int indegree[501];
int g[501][501];
int a[501];
void init()
{
    for (int i = 0; i < 501; i++)
    {
        a[i] = indegree[i] = 0;
        for (int j = 0; j < 501; j++)
        {
            g[i][j] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        int n, m, F = -1;
        cin >> n;
        init();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                g[a[i]][a[j]] = 1;
                indegree[a[j]]++;
            }
        }

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;

            if (g[x][y] == 1)
            {
                indegree[x]++;
                indegree[y]--;
                swap(g[x][y], g[y][x]);
            }
            else if (g[y][x] == 1)
            {
                indegree[y]++;
                indegree[x]--;
                swap(g[x][y], g[y][x]);
            }
        }

        queue<int> q;
        queue<int> ans;

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                ans.push(i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (q.size() == 0)
            {
                F = 0;
                break;
            }

            if (q.size() >= 2)
            {
                F = 1;
                break;
            }

            int here = q.front();
            q.pop();

            for (int i = 1; i <= n; i++)
            {
                if (g[here][i] == 1)
                {
                    indegree[i]--;
                    if (indegree[i] == 0)
                    {
                        q.push(i);
                        ans.push(i);
                    }
                }
            }
        }

        if (F == 0)
        {
            cout << "IMPOSSIBLE\n";
        }
        else if (F == 1)
        {
            cout << "?\n";
        }
        else
        {
            while (!ans.empty())
            {
                cout << ans.front() << " ";
                ans.pop();
            }
            cout << "\n";
        }
    }
    return 0;
}
