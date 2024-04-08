#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;

    while(t--){
        ll n, k, x; cin >> n >> k >> x;
        if(n < k or k > x + 1 ){
            cout << -1 << endl;
        }else{
            ll ans = 0;
            if(k == x){
                ans = (k* (k-1))/2;
                ans += (n - k) * (x-1);
            }else{
                ans = (k* (k-1))/2;
                ans += (n - k) * (x);
            }
            cout << ans << endl;
        }
        
    }
}