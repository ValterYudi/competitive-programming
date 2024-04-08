#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(a < b and b < c){
        cout << "STAIR\n";
    }else if(a < b and b > c){
        cout << "PEAK\n";
    }else{
        cout << "NONE\n";
    
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
