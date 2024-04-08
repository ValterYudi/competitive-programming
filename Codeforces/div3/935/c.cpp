#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
bool check(vi &count_l, vi &count_r, int i){
    int n = count_l.size();
    int l = count_l[i], r = count_r[i];
    if(i == n-1) {
        r = 0;
    }else r = count_r[i+1];
    //if(i == 1) cout << l << " " << r << endl;
    if(l > (i+1)/2 or r > (n-i-1)/2) return 0;
    return 1;
    //pos = 1
    //l = 1, r = 1

}

void solve1(){
    ll n; cin >> n;
    vi a(n, 0), count_l(n, 0), count_r(n, 0);
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        a[i] = s[i] - '0';
    }
    for(int i = 0; i < n; i++){
        if(i == 0){
            count_l[0] = (a[0] == 1);
            count_r[n-1] = (a[n-1] == 0);
        }else{
            count_l[i] = count_l[i-1] + (a[i] == 1);
            count_r[n-1-i] = count_r[n-i] + (a[n-1-i] == 0);
        }
    }
    
    vi ans;
    for(int i = 0; i < n; i++){
        if(check(count_l, count_r, i)){
            ans.push_back(i+1);
        }
    }
    if(count_r[0] <= n/2) ans.push_back(0);
    //find the ans that is the most close to n/2
    
    int m = ans.size();
    ld mid = ld(n)/ld(2);
    ld diff = ld(INT_MAX);
    int index = -1;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < m; i++){
        if(abs(ld(ans[i]) - mid) < diff){
            diff = abs(ans[i] - mid);
            index = i;
        }
        //cout << ans[i] << " ";
    }
    //cout << endl;
    cout << ans[index] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}