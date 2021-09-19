#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k;

struct node
{
    string data;
    map<string, node *> mp;
    node() { data = "", mp.clear(); }
};

class Trie
{
public:
    node *root;
    Trie() { root = new node(); }

    void set(node *current, string s)
    {
        if (current->mp[s] == nullptr)
            current->mp[s] = new node();

        current->mp[s]->data = s;
    }

    void find(node *current, ll depth)
    {
        if (current == nullptr)
            return;

        for (ll i = 1; i < depth; i++)
            cout << "--";

        if (current != root)
            cout << current->data << '\n';

        for (auto next : current->mp)
            find(next.second, depth + 1);
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Trie trie;
    while (n--)
    {
        cin >> k;
        node *current = trie.root;
        string in;
        while (k--)
        {
            cin >> in;
            trie.set(current, in);
            current = current->mp[in];
        }
    }
    trie.find(trie.root, 0);
    return 0;
}
