#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> ii;

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> o_set;

#define first F;
#define second S;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    o_set s;
    for (int i = 0; i < n; i++){
        s.insert({a[i], i});
    }

    while (q--) {
        char c; cin >> c;
        if (c == '!') {
            int k, x; cin >> k >> x;
            k--;
            s.erase(s.find({a[k], k}));
            a[k] = x;
            s.insert({x, k});
        } else {
            int a, b; cin >> a >> b;
            int ans = s.order_of_key({b, n}) - s.order_of_key({a, 0});
            cout << ans << "\n";
        }
    }
}