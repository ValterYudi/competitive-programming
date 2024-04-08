#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

    

void solve(){
    ll n; cin >> n;
    ll soma = 0;
    for(ll i = 0; i < n;i ++){
        ll alt; cin >>alt;
        soma += ((alt-1) * i) + alt;
    }
    cout << soma << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
