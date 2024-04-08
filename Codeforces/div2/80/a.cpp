#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    int n; cin >> n;
    n -= 10;
    if(n == 10) cout << "15\n";
    else if(n <= 0 or n > 11){
        cout << "0\n";
    }else{
        cout << "4\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
