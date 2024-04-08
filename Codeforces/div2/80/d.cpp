#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    ll n, k, p; cin >> n >> k >> p;
    if(!k){
        for(int i = 0; i < p; i++){
            ll q; cin >>q;
            cout << '.';
        }
        cout << endl;
        return;
    }
    while(p--){
        ll q; cin >> q;
        if(q == n){
            cout << 'X';
            continue;
        }
        if(q%2){
            ll aux = (n/2) + (n%2);
            aux +=((n - q - 1)/2) + 1;
            if(aux <= k) cout << 'X';
            else cout << '.';
        }else{
            ll aux = ((n - q)/2) + 1 + (n%2);
            if(aux <= k) cout << 'X';
            else cout << '.';
        }
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
// ...X.X