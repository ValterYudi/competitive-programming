#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll a, b, m; cin >> a >> b >> m;
    ll ans = 0;
    ans += (m/a) + 1;
    ans +=(m/b) + 1;
    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}