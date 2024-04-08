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
        int n; cin >> n;
        vi v(n), ans(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        if(v[0] == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
