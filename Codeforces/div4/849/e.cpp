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
        vector<ll> v(n);
        ll aux = 0, check = 0, big = 1e9, lil = -1e9, count_lil = 0;
        for(auto &a:v){
            cin >> a;
            aux += abs(a);
            if(a < 0){
                lil = max(lil, a);
                count_lil++;
            }
            else if(a == 0) check = 1;
            else big = min(big, a);
        }
        if(check) cout << aux << endl;
        else{
            if(count_lil%2){
                cout << aux - (min(abs(lil), big)*2) << endl;
            }else cout << aux << endl;
        }

    }
}