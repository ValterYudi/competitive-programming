#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
//include ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//define ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> o_set;

int main() {
    int n, q; cin >> n >> q;
    vector<pair<int, int>> a(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].F = i;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        pos[i].F = a[i].S;
        pos[i].S = i;
    }
    sort(pos.begin(), pos.end());


    // for(auto x : s) cout << x << " ";
    // cout << endl;
    while (q--) {
        char c; cin >> c;
        if (c == '!') {
            int k, x; cin >> k >> x;
            k--;
            int pos_atual = pos[k].S;
            int pos_to_insert = lower_bound(pos.begin(), pos.end(), make_pair(x, k)) - pos.begin();
            
        } else {
            int a, b; cin >> a >> b;
            //find the number of elements in the set that are less than or equal to b and bigger than or equal to a
            int ans = distance(s.lower_bound(a), s.upper_bound(b));
            cout << ans << "\n";
        }
    }
}