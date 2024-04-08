#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(a + b + c == 1){
        if(c==1)cout << "0\n";
        else cout << "-1\n";
    }else if(a + b + c == 2){
        if (b == 1 and c == 1){
            cout << "1\n";
        }else{
            cout << "-1\n";
        }
    }else if(a + b + c == 3){
        if(c != 3){
            cout << "1\n";
        }else{
            cout << "-1\n";
        }
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
