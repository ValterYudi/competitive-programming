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
        int n; cin >> n;
        int low= 0, up = 1000000001;
        vi ne;
        for(int i = 0; i < n; i++){
            int op, x; cin >> op >> x;
            if(op == 1){
                low = max(low, x);
            }else if(op == 2){
                up = min(up, x);
            }else{
                ne.push_back(x);
            }
        }
        int count = up - low + 1;
        for(auto x : ne){
            if(x >= low && x <= up){
                count--;
            }
        }
        cout << max(count, 0) << endl;
    }
    return 0;
}
