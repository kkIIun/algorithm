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
set<tuple<ll, ll, ll>> visited ;
queue<tuple<ll, ll, ll>> q;
vector<ll> v;
ll ans = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    if (( a+ b+ c)%3 != 0){
        cout << ans << '\n';
        return 0;
    }
    
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    q.push(make_tuple(v[0],v[1],v[2]));
    visited.insert(make_tuple(v[0], v[1], v[2]));
    while(!q.empty()){
        v[0] = get<0>(q.front());
        v[1] = get<1>(q.front());
        v[2] = get<2>(q.front());
        sort(v.begin(), v.end());
        a = v[0];
        b = v[1];
        c = v[2];
        q.pop();
        
        if (a==b && b==c){
            ans = 1;
            break;
        }

        ll na, nb, nc;
        
        if (a != b){
            na = 2*a;
            nb = b-a;
            nc = c;
            if (visited.find(make_tuple(na, nb, nc)) == visited.end()){
                q.push(make_tuple(na, nb, nc));
                visited.insert(make_tuple(na, nb, nc));
            }
        }

        if (a != c){
            na = 2*a;
            nb = b;
            nc = c-a;
            if (visited.find(make_tuple(na, nb, nc)) == visited.end()){
                q.push(make_tuple(na, nb, nc));
                visited.insert(make_tuple(na, nb, nc));
            }
        } 

        if( b != c){
            na = a;
            nb = 2*b;
            nc = c-b;
            if (visited.find(make_tuple(na, nb, nc)) == visited.end()){
                q.push(make_tuple(na, nb, nc));
                visited.insert(make_tuple(na, nb, nc));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
