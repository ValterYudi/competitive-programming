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
        int n, m; cin >> n >> m;
        vector<int> v(n, 0), somas;
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int mask = 0; mask < (1 << (n/2)); mask++){
            int sum = 0;
            for(int i = 0; i < n/2; i++){
                if(mask & (1 << i) ){
                    sum += v[i];
                }
                sum %= m;
                if(sum == m-1){
                    cout << sum << "\n";
                    return 0;
                }
            }
            somas.push_back(sum);
        }
        sort(somas.begin(), somas.end());
        int ans = somas.back();
        for(int mask = 0; mask < (1 << (n - n/2)); mask++){
            int sum = 0;
            for(int i = 0; i < n - n/2; i++){
                if(mask & (1 << i)){
                    sum += v[i + n/2];
                }
                sum %= m;
                if(sum == m - 1){
                    cout << sum <<  "\n";
                    return 0;
                }
            }
            int need = m - sum - 1;
            auto it = upper_bound(somas.begin(), somas.end(), need);
            if(it != somas.begin()){
                it--;
                ans = max(ans, (sum + *it) % m);
            }
        }

        cout << ans << endl;
    }
}