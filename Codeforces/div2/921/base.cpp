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
        int x, n; cin >> x >> n;
        int mx = x/n, rest = x%n, maior = 1;
        if(rest == 0){
            maior = mx;
            cout << maior << endl;
            continue;
        }
        while(mx > 1){
            int gt = __gcd(rest+mx, mx);
            if(gt > maior){
                maior = gt;
                break;
            }
            mx--;
            rest = x - (mx*n);
        }
        mx = x/n; rest = x%n;
        while(mx < x/(n-1)){
            int gt = __gcd(rest+mx, mx);
            if(gt > maior){
                maior = gt;
                break;
            }
            mx++;
            rest = x - (mx*n);
        }
        cout << maior << endl;
    }
}
