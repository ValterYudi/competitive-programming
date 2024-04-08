#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll ans = 0, mini = 1e9, pos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < mini){
            mini = a[i];
            pos = i;
        }
    }
    for(int i = pos+1; i < n; i++){
        if(a[i-1] > a[i]){
            cout << -1 << endl;
            return;
        }
    }
    cout << pos << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
    solve();
    
    return 0;
}