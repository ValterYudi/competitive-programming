#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll a, b, c; cin >> a >> b >> c;
    int ans = a;
    if(b%3 == 2 and c >= 1){
        ans += (b/3) + 1;
        c--;
        if(c >= 3){
            ans += c/3;
            ans += (c%3 > 0);
        }else if(c > 0){
            ans++;
        }
    }else if(b%3 == 1 and c >= 2){
        if(b >= 3) ans += (b/3);
        ans++;
        c -= 2;
        if(c >= 3){
            ans += c/3;
            ans += (c%3 >0);
        }else if(c > 0){
            ans++;
        }
    }else if(b%3 == 0){
        ans += b/3;
        ans += c/3;
        ans += (c%3 > 0);
    }else{
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}