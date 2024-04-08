#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n, k; cin >> n >> k;
    ll soma = n * (n + 1) / 2, media = soma / k;
    vi ans(n, 0);
    int l = 1, r = n;
    int i = 0, muda = 0, last_ini = 0;
    while(l <= r){
        if(muda) ans[i] = r--;
        else ans[i] = l++;
        i+=k;
        if(i >= n){
            muda = muda ^ 1;
            i = last_ini + 1;
            last_ini = i;
        }
    }
    for(auto &a : ans)
        cout << a << " ";
    
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}