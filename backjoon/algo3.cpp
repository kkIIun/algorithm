#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

ll ans = 0;

struct max_heap
{
    ll heap[100000], len = 0;
    void push(ll n);
    void pop();
    ll top();
};

ll max_heap::top()
{
    return heap[1];
}

void max_heap::push(ll n)
{
    heap[++len] = n;
    ll node = len;
    while (node != 1 && heap[node] > heap[node / 2])
    {
        swap(heap[node], heap[node / 2]);
        node /= 2;
    }
}

void max_heap::pop()
{
    swap(heap[1], heap[len]);
    heap[len--] = 0;
    ll node = 1;
    while (node * 2 <= len && (heap[node] < heap[node * 2] || heap[node] < heap[node * 2 + 1]))
    {
        if (heap[node * 2] > heap[node * 2 + 1] || !heap[node * 2 + 1])
        {
            swap(heap[node], heap[node * 2]);
            node = node * 2;
        }
        else
        {
            swap(heap[node], heap[node * 2 + 1]);
            node = node * 2 + 1;
        }
    }
}

void solve()
{
    ll In, n;
    cin >> n;
    max_heap maxh, minh;
    for (ll i = 1; i <= n; i++)
    {
        cin >> In;
        if (!maxh.len)
        {
            maxh.push(In);
            ans += In;
        }
        else if (!minh.len)
        {
            ll temp = maxh.top();
            if (temp > In)
            {
                maxh.pop();
                maxh.push(In);
                minh.push(-temp);
            }
            else
                minh.push(-In);
            ans += (In + temp) / 2;
        }
        else
        {
            if (i % 2)
            {
                ll minT = -minh.top();
                if (minT < In)
                {
                    minh.pop();
                    maxh.push(minT);
                    minh.push(-In);
                }
                else
                    maxh.push(In);
                ans += maxh.top();
            }
            else
            {
                ll maxT = maxh.top();
                if (maxT > In)
                {
                    maxh.pop();
                    maxh.push(In);
                    minh.push(-maxT);
                }
                else
                    minh.push(-In);
                ans += (maxh.top() - minh.top()) / 2;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll TC;
    cin >> TC;
    while (TC--)
    {
        ans = 0;
        solve();
        cout << ans % 10 << '\n';
    }
    return 0;
}