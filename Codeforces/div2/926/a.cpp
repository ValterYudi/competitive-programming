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
        int n, k; cin >> n >> k;
        int ans = 0, teto = n*4 - 2, count = 0;
        if(k%2 == 0){
            ans = k/2;
        }else{
            ans = (k+1)/2;
        }
            
        if(k == teto){
            ans = 2*n;
        }else if(k == teto-1){
            ans = 2*n-1;
        }
        cout << ans << endl;
    }
}
