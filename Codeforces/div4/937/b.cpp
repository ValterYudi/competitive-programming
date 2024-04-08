#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    int n; cin >> n;
    char c = '.', d = '#';
    for(int i = 0; i < (2*n); i++){
        if(i%2 == 0){
            d = (d == '.' ? '#' : '.');
        }
        c = d;
        for(int j = 0; j < 2*n; j++){
            if(j%2 == 0){
                c = (c == '.' ? '#' : '.');
            }
            cout << c;
        }
        cout << endl;
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
