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
        ll n; cin >> n;
        vector<string> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];
        ll ans = 0;
        for(int i = 0; i <= (n+1)/2; i++){
            for(int j = i; j < n-i ;j++){
                char maior = max({int(v[i][j]), int(v[j][n - i - 1]), int(v[n - j - 1][i]), int(v[n - i - 1][n - j - 1])});
                ans += int(maior) - int(v[i][j]);
                ans += int(maior) - int(v[j][n - i - 1]);
                ans += int(maior) - int(v[n - j - 1][i]);
                ans += int(maior) - int(v[n - i - 1][n - j - 1]);

                v[i][j] = v[j][n - i - 1] = v[n - j - 1][i] = v[n - i - 1][n - j - 1] = maior;
            }
        }
        cout << ans << endl;
    }

}