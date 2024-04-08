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
        vi v(n);
        for(auto &x : v) cin >> x;
        int mex = 0;
        set<int> s, s2;
        
        for(int i = 0; i < n; i++){
            s.insert(v[i]);
            if(v[i] == mex){
                while(s.count(mex)) mex++;
            }
        }
        //cout << mex << endl;
        int l=0, r=0;
        int mex_aux = 0;
        vector<ii> ans;
        if(mex == 0){
            for(int i = 0; i < n; i++){
                ans.push_back({i+1, i+1});
            }
        }else{
            while(r < n && l < n){
                if(v[r] == mex_aux){
                    mex_aux++;
                    while(s2.count(mex_aux)) mex_aux++;
                    if(mex_aux == mex){
                        ans.push_back({l+1, r+1});
                        s2.clear();
                        mex_aux = 0;
                        r++;
                        l = r;
                    }else{
                        s2.insert(v[r]);
                        r++;
                    }
                }else{
                    s2.insert(v[r]);
                    r++;
                }
            }
        }
        if(ans.back().second != n){
            ans.back().second = n;
        }
        if(ans.size() <= 1){
            cout << -1 << endl;
        }else{
            cout << ans.size() << endl;
            for(auto x : ans){
                cout << x.first << " " << x.second << endl;
            }
        }
    }
}
