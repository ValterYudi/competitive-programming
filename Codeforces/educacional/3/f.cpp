#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t; 
    while(t--){
        ll n, m, soma = 0; cin >> n;
        vector<ll> v(n, 0);
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            soma += a;
            v[i] = a;
        }
        sort(v.begin(), v.end());
        ll ans = 0, med = soma/n, rest = n - (soma%n);
        for(int i = 0; i < n; i++){
            if(rest == 0){
                med++;
            }
            ans += abs(med - v[i]);
            rest--;
        }
        cout << ans/2 << endl;
    }
}