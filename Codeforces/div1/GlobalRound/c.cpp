#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define MIN -1000000000
#define F first
#define S second

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll last = n-1;
    while(k > 0){
        ll menor = 1e18, aux = k / m;
        for(ll i = last; i >= aux; i--){
            menor = min(menor, (v[i]*m) + (aux*(k-m)));
        }
        k -= m;
    }

    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  
    cin >> t; 
    
    while(t--){
        solve();
        
    }
    return 0;
}
