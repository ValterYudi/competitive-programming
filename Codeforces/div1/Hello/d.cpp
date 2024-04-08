#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n), b(n), c(n-1);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    for (ll &x : c) cin >> x;

    vector<pair<ll, int>> towers(n);
    for (int i = 0; i < n; ++i) {
        towers[i] = {min(a[i], b[i]), i};
    }
    sort(towers.begin(), towers.end());

    while (q--) {
        int p;
        ll x, y, z;
        cin >> p >> x >> y >> z;

        a[p-1] = x;
        b[p-1] = y;
        if (p != n) c[p-1] = z;

        towers[p-1] = {min(a[p-1], b[p-1]), p-1};
        sort(towers.begin(), towers.end());

        ll res = 0;
        for (auto &tower : towers) {
            res += tower.first;
        }

        cout << res << '\n';
    }

    return 0;
}
