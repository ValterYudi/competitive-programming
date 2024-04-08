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
        int n, q; cin >> n >> q;
        vi a(n), onda(n, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        while(q--){
            int tipo; cin >> tipo;
            if(tipo == 1){
                int l, r; cin >> l >> r;
                l--; r--;
                for(int i = l; i <= r; i++){
                    onda[i] += a[i] - a[l];
                }
            }else{
                int k; cin >> k;
                cout << checa << endl;
            }
        }
    }
}