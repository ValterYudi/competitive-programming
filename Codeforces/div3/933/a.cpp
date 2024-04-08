#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n, m , k; cin >> n >> m >> k;
    vi b(n), c(m);
    for(auto &a :  b) cin >> a;
    for(auto &a :  c) cin >> a;
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(b[i] < k){
            auto it = upper_bound(c.begin(), c.end(), k - b[i]);
            cont += (it - c.begin());
        }else{
            break;
        }
    }
    cout << cont << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}