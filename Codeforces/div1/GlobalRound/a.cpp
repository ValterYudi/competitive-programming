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
    int n; cin >> n;
    string s; cin >> s;
    bool adj = false;
    char ant = 'f';
    int cont = 0;
    for(auto c : s){
        if(ant == c and c == '1') adj = 1;
        if(c == '1') cont++;
        ant = c;
    }
    if(cont%2){
        cout << "NO\n";
    }else{
        if(adj and cont == 2) cout << "NO\n";
        else cout << "YES\n";
    }
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
