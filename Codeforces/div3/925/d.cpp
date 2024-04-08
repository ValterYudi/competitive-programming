#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

ll soma_pa(ll n){
    return n*(n+1)/2;
}

void solve1(){
    ll n, x, y; cin >> n >> x >> y;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, vector<int>> freq;
    set<int> s;
    for(int i = 0; i < n; i++){
        freq[a[i] % y].push_back(a[i]%x);
    }
    ll ans = 0;
    for(auto [k, v] : freq){
        cout <<"resto: "<< k << " pares: " << v[0] << " pos i: " << v[1] <<" pos j: " << v[2] << '\n';
        if(v.size() > 1){
            // achar quantos pares s
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}