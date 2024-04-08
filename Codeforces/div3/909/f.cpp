#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve(){
    ll n; cin >> n;
    vector<ll> a(n), ps(n+1);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  ps[i+1] = ps[i] + a[i];
    ll ans = 0;
    for(int i = 1; i <= (n/2); i++){
        if(n % i != 0)  continue;
        ll mzao = 0, mzin = 1e18;
        for(int j = 0; j < n; j += i){
            mzao = max(mzao, ps[j+i]-ps[j]);
            mzin = min(mzin, ps[j+i]-ps[j]);
        }
        //cout << i << " " << mzao << " " << mzin << "\n";
        ans = max(ans, mzao-mzin);
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
    solve();
    
    return 0;
}