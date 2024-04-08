#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        ll a, b, r; cin >> a >> b >> r;
        //find a value x that minimizes the function f(x) = abs((a ^ x) - (b ^ x))

        //if a == b, then the function is 0 for any x
        if(a == b){
            cout << 0 << endl;
            continue;
        }
        ll ans = a ^ b;
        ans &= r;

        ll f_ans = abs((a ^ ans) - (b ^ ans));
        
        cout << f_ans << endl;
    }
}
