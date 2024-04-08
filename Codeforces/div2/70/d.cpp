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
        int n; cin >> n;
        n--;
        int ans = 1, circle = n/3;
        circle *= 2;
        if(n%3 == 0){
            ans += ((circle+1)*6)*circle/2;
            ans -= (circle*3);
            //cout << "oi0\n";
        }else if(n%3 == 1){
            ans += ((circle+1)*6)*circle/2;
            //cout << "oi1\n";
        }else if(n%3 == 2){
            circle++;
            ans += ((circle+1)*6)*circle/2;
            //cout << "oi2\n";
        }
        cout << ans << endl;
    }
}
