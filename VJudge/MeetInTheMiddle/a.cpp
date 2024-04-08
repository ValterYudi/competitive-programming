#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

typedef unordered_map<ll, ll> u_m;

ll v[41], x;

void solve(u_m &dp, ll i, ll soma, ll max_i){
    ll pegar = v[i] + soma;
    if(i >= max_i) return;

    if(pegar <= x){
        dp[pegar]++;
        solve(dp, i+1, pegar, max_i);
    }

    solve(dp, i+1, soma, max_i);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n; cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> v[i];
	sort(v, v+n);
    ll ans = 0;
    u_m dpL, dpR;
    solve(dpL, 0, 0, n/2);
    for(int mask = 0; mask < (1 << (n - n / 2)); mask++) {
        ll sum = 0;
        for(int i = 0; i < n - n / 2; i++) {
            if(mask & (1 << i))
                sum += v[i + n / 2];
			if(sum > x) break;
        }
        if(sum <=x) ans += (x-sum==0) ? 1 : dpL[x-sum]; 
    }

    cout << ans << endl;
}