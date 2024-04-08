#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;



ll dp_coins(vector<ll> &v, int k, ll fator, int pos, vector<map<int, ll>> &memo){
    int n = v.size();
    if(pos == n) return 0;
    if(memo[pos].count(fator) > 0) return memo[pos][fator];
    ll chave_boa = v[pos]/fator + dp_coins(v, k, fator, pos+1, memo) - k;
    ll chave_ruim = v[pos]/ll(2*fator) + dp_coins(v, k, fator*2, pos+1, memo);
    return memo[pos][fator] = max(chave_boa, chave_ruim);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >>k;
        vector<map<int, ll>> memo(n);
        vector<ll> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        ll ans = dp_coins(v, k, 1, 0, memo);
        cout << ans << endl;
    }
}