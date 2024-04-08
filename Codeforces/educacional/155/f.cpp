#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main() {
    int n, d; cin >> n >> d;
    vector<pair<int, int>> v(n);
    vi positions(d);
    for (int i = 0; i < d; i++) positions[i] = i;

    for(int i=0; i<n; i++) cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    ll ans = 0;
    for(int i=0; i<n; i++){
        if(v[i].second <= d){
            auto it = lower_bound(positions.begin(), positions.end(), (d-v[i].second));
            cout << "dias: " << v[i].second << " valor: " << (v[i].first) << endl;
            cout << "it: " << *it << endl;
            int pos = it - positions.begin();
            cout << "pos: " << pos << " positions[pos]: " << positions[pos] << endl;
            cout << "(d-v[i].second): " << (d-v[i].second) << endl;
            if(it == positions.end() or (pos == 0 and (d-v[i].second) < positions[pos])) continue;
            ans += v[i].first;
            positions.erase(positions.begin() + positions[pos]);
        }
    }
    cout << ans << endl;
}
