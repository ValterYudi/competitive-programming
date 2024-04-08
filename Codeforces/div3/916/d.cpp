#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define MIN -1000000000
#define F first
#define S second
int dp(vector<ii> &a, vector<ii> &b, int pego){
    int ans = 0;
    for(int i=0; i<3; i++){
        if(b[i].S == pego){
            continue;
        }
        int aux_a = 0;
        for(int j=0; j<3; j++){
            if(a[j].S == pego || a[j].S == b[i].S){
                continue;
            }
            aux_a = max(aux_a, b[i].F + a[j].F);
        }
        ans = max(ans, aux_a);
    }
    return ans;

}
void solve1(){
    ll n; cin >> n;
    vector<ii> a(n), b(n), c(n); 
    for(int i=0; i<n; i++){
        cin >> a[i].F;
        a[i].S = i;
    }
    for(int i=0; i<n; i++){
        cin >> b[i].F;
        b[i].S = i;
    }
    for(int i=0; i<n; i++){
        cin >> c[i].F;
        c[i].S = i;
    }
    sort(a.begin(), a.end(), greater<ii>());
    sort(b.begin(), b.end(), greater<ii>());
    sort(c.begin(), c.end(), greater<ii>());

    int ans = max({c[0].F + dp(a, b, c[0].S), b[0].F + dp(a, c, b[0].S), a[0].F + dp(b, c, a[0].S)});
    
    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}