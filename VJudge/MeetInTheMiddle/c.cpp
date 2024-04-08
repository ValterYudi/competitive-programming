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
        int n, x;  cin >> n >> x;
        vector<int> v;
        vector<pair<int, array<int, 2>>> somas;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            v.push_back(a);
        }
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                if(v[i] + v[j] < x - 1)somas.push_back({v[i] + v[j], {i, j}});
            }
        }
        sort(somas.begin(), somas.end());

        for(int i = 0; i < somas.size(); i++){
            int a = somas[i].first;
            int l = somas[i].second[0];
            int r = somas[i].second[1];
            auto it = lower_bound(somas.begin(), somas.end(), make_pair(x - a, array<int, 2>{0, 0}));
            if(it != somas.end() && it->first == x - a && it->second[0] != l && it->second[1] != r && it->second[0] != r && it->second[1] != l){
                array<int, 4> ans = {l, r, it->second[0], it->second[1]};
                sort(ans.begin(), ans.end());
                cout << ans[0]+1 << " " << ans[1]+1 << " " << ans[2]+1 << " " << ans[3]+1 << endl;
                return 0;
            }
        }
        cout << "IMPOSSIBLE" << endl;
        
    }
}
