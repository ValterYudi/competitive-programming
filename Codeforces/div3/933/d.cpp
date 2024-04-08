#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n, m, x; cin >> n >> m >> x;
    vi v(n);
    set<int> states, aux;
    states.insert(x-1);
    for(int i = 0; i < m; i++){
        int mvs; cin >> mvs;
        char c; cin >> c;
        for(auto e: states){
            mvs %= n;
            if(c != '1') aux.insert((e+mvs)%n);
            if(c != '0') aux.insert((e-mvs+n)%n);
        }
        states = aux;
        aux.clear();
    }
    cout << states.size() << '\n';
    for(auto e: states) cout << e+1 << ' ';
    cout << '\n';
    states.clear();
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  
    cin >> t; 
    while(t--)
        solve1();
    
    return 0;
}