#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define MIN -1000000000
#define F first
#define S second


int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  
    cin >> t; 
    
    while(t--){
        int n, al, bob; cin >> n >> al >> bob;
        vi v(n), pf(n+1, 0);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < n; i++){
            pf[i+1] = pf[i] + v[i];
        }
        int soma = pf[n];
        int ans = -1000000001, pos = 0;
        for(int i = al; i >=0; i--){
            int bobs_rm = 2*(pf[i] - pf[min(i+bob, n)]);
            int ali_rm = (pf[i] - pf[0]);
            int aux = soma - ali_rm + bobs_rm;
            ans = max(ans, aux);
        }
        cout << ans << endl;
    }
    return 0;
}
