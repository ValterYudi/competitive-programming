#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n, m, k; cin >> n >> m >> k;
    vi a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    set<int> sa, sb, inter;
    for(auto x : a) if(x <= k) sa.insert(x);
    for(auto x : b){
        if(sa.count(x)) inter.insert(x);
        if(x <= k) sb.insert(x);
    }
    bool check = ((sa.size() + sb.size() - inter.size()) == k);
    if(check){
        if(sa.size() > sb.size()){
            if(sa.size() - inter.size() > k/2){
                check = false;
            }
        }else if(sa.size() < sb.size()){
            if(sb.size() - inter.size() > k/2){
                check = false;
            }
        }
    }
    cout << (check ? "YES" : "NO") << endl;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}