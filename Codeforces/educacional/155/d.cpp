#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n), acc_xor(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        ll ans = 0;
        ll xor_ij = 0;

        for (int i = 0; i < n; i++) {
            xor_ij ^= v[i];
            ans += (xor_ij * (i + 1)) % MOD;
            ans %= MOD;
        }

        cout << ans << endl;
    }
    return 0;
}
