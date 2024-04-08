#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;




int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        sort(heights.begin(), heights.end());
        int max_height = heights[n - 1];
        ll acc = 0;
        for(int i = 0; i < n; i++){
            acc += max_height - heights[i];
        }
        if(acc == x){
            cout << max_height << endl;
        }else if(acc < x){
            ll diff = x - acc;
            int ans = (diff / n);
            ans += max_height;
            cout << ans << endl;
        }else{
            vector<ll> acc_heights(n);
            acc_heights[0] = heights[0];
            for(int i = 1; i < n; i++){
                acc_heights[i] = acc_heights[i-1] + heights[i];
            }
            ll l = 0, r = max_height, target = 0;
            while(l <= r){
                ll mid = (l+r)/2;
                ll pos = upper_bound(heights.begin(), heights.end(), mid) - heights.begin();
                ll aux = (pos)*mid;
                if(pos > 0){
                    aux -= acc_heights[pos-1];
                }
                if(aux == x){
                    target = mid;
                    break;
                }else if(aux < x){
                    target = mid;
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            cout << target << endl;
        }


    }
    
    return 0;
}