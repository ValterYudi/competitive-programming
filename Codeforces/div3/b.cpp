#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n, k, target = -1; cin >> n >> k;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        b.push_back(x);
    }sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vi ans;
    for(int l = 0, r = 0; l < n and r < n;){
        if(a[l] == b[r]){
            ans.push_back(a[l]);
            l++;
            r++;
        }else if(a[l] > b[r]){
            r++;
        }else{
            l++;
        }
    }
    cout << ans.size() << '\n';
    // for(int i = 0; i < k*2; i++) cout << ans[i] << ' ';
    // cout << '\n';
    // for(int i = 0; i < k*2; i++) cout << ans[i] << ' ';
    // cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}