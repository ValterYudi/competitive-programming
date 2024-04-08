#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n; cin >> n;
    vi v(n);
    for(auto &a: v) cin >> a;
    int cont_ant = 0;
    for(int i = 1; i < n - 1; i++){
        v[i] -= (v[i-1]*2);
        v[i+1] -= (v[i-1]);
        v[i-1] = 0;
        if(v[i] < 0){
            cout << "NO\n";
            return;
        }
    }
    if(v[n-1] != 0 or v[n-2] != 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}