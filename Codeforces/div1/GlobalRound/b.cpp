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
    int n, p; cin >> n >> p;
    vi v(n);
    for(auto &a : v) cin >> a;
    int cow = v[p-1], cont = 0, cont1 = 0, cont2 = 0, swap = 0;
    for(int i = 0; i < n; i++){
        if(i == p-1){
            swap = 1;
            continue;
        }
        if(v[i] < cow) cont++;
        else if(!swap){
            swap = 1;
            v[p-1] = v[i];
            p = i + 1;
            cont1 = cont - 1;
            cont = cont > 0;
        }
        else break;
    }
    cout << max(cont, cont1) << endl;
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
