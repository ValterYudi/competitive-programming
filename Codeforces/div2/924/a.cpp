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
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        if(a % 2 == 0){
            if(b == a / 2) cout << "NO\n";
            else cout << "YES\n";
        }else if (b % 2 == 0){
            if(a == b / 2) cout << "NO\n";
            else cout << "YES\n";
        }else cout << "NO\n";
    }
}
