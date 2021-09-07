#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<char, ll> dic = {
    {'+', 2},
    {'-', 2},
    {'*', 1},
    {'/', 1},
    {'(', 3},
    {')', 3},
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<char> stk;
    string s;
    cin >> s;
    for (ll i = 0; i < s.size(); i++)
    {
        if (dic.find(s[i]) == dic.end())
            cout << s[i];
        else
        {
            if (s[i] == '(')
                stk.push(s[i]);
            else if (s[i] == ')')
            {
                while (stk.top() != '(')
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else
            {
                while (!stk.empty() && dic[stk.top()] <= dic[s[i]])
                {
                    cout << stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}
