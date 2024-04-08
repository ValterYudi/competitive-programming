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
        int n; cin >> n;
        set<int> s;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            s.insert(x);
        }
        vi v(s.begin(), s.end());
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            int aux = upper_bound(v.begin(), v.end(), v[i]+n-1) - v.begin();
            ans = max(ans, aux-i);
        }
        cout << ans << endl;
    }
}
