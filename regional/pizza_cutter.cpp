#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

typedef
tree<
  int,
  null_type,//opcional
  greater<int>,//a ordem que você quer para a sua árvore
  rb_tree_tag,
  tree_order_statistics_node_update>
map_t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll x, y, h, v; cin >> x >> y >> h >> v;
    ll ih = 0, iv = 0;
    vector<pair<int,int>> hor(h), ver(v);

    for(auto &it : hor){
        cin >> it.first >> it.second;
    }
    
    sort(hor.begin(), hor.end());
    map_t intersec;
    for(ll i = 0; i < h; i++){
        ih += intersec.order_of_key(hor[i].second);
        intersec.insert(hor[i].second);
    }

    for(auto &it : ver){
        cin >> it.first >> it.second;
    }
    
    sort(ver.begin(), ver.end());
    intersec.clear();
    for(ll i = 0; i < v; i++){
        iv += intersec.order_of_key(ver[i].second);
        intersec.insert(ver[i].second);
    }

    ll ans = (h + 1) * (v + 1) + ih + iv;

    cout << ans << "\n";
}