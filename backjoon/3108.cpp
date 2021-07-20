#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <limits>
#include <set>
using namespace std;

typedef long long ll;
ll visited[1010][1010];
pair<ll, ll> center = make_pair(500, 500);
ll n;
ll parent[1001];
vector<pair<pair<ll, ll>, pair<ll, ll> > > point;
set<int> s;

int getParent(int a){
    if (parent[a] == a)
        return a;
    return parent[a] = getParent(parent[a]);
}

void Union(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(a > b) 
        parent[b] = a; 
    else if(b > a)
        parent[a] = b;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visited, -1, sizeof(visited));
    cin >> n;
    for(ll i =0; i< n; i++)
        parent[i] = i;
    for (ll i = 0; i < n; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        point.push_back(make_pair(make_pair(a + 500, b + 500),make_pair(c + 500, d + 500)));
    }

    for (ll i = 0; i < n; i++)
    {
        ll x1, y1, x2, y2;        

        x1 = point[i].first.first;
        y1 = point[i].first.second;
        x2 = point[i].second.first;
        y2 = point[i].second.second;
        for (ll dx = x1; dx <= x2; dx++)
        {
            if (visited[dx][y1] != -1)
                Union(visited[dx][y1], i);
            else 
                visited[dx][y1] = i;
            
            if (visited[dx][y2] != -1)
                Union(visited[dx][y2], i);
            else
                visited[dx][y2] = i;
        }
        for (ll dy = y1 + 1; dy < y2; dy++)
        {   
            if (visited[x1][dy] != -1)
                Union(visited[x1][dy], i);
            else 
                visited[x1][dy] = i;
            
            if (visited[x2][dy] != -1)
                Union(visited[x2][dy], i);
            else
                visited[x2][dy] = i;
        }
    }
    for (ll i = 0; i < point.size(); i++)
        s.insert(getParent(parent[i]));
    
    if (visited[500][500] != -1)
        cout << s.size() -1;
    else 
        cout << s.size();
    return 0;
}
