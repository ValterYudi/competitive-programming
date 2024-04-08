#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        ll sum_a = 0, sum_b = 0, ma = LLONG_MAX, mb = LLONG_MAX;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum_a += a[i];
            ma = min(ma, a[i]);
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            sum_b += b[i];
            mb = min(mb, b[i]);
        }
        sum_a += (mb*n);
        sum_b += (ma*n);
        cout << min(sum_a, sum_b) << endl;
    }
}