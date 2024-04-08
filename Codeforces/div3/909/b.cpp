#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    ll maior = -1e9;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maior = max(maior, a[i]);
    }
    ll ans = a[0], parity = abs(a[0]%2), f_ans = a[0];
    for(int i = 1; i < n; i++){
        if(ans < 0) ans = 0;
        if((parity) != abs(a[i] % 2)){
            ans += a[i];
            parity ^= 1;
            f_ans = max(f_ans, ans);
        }
        else{
            ans = a[i];
            f_ans = max(f_ans, ans);
        }
    }
    if(f_ans == 0)  f_ans = maior;
    
    cout << f_ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
    solve();
    
    return 0;
}