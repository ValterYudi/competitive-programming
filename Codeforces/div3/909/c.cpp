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
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    //int t = 1;  cin >> t; while(t--)
    solve();
    
    return 0;
}