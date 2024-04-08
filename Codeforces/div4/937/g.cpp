#include<bits/stdc++.h>

#define INF 1e9
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    int n; cin >> n;
    vector<pair<string, string>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    int ans = INF;
    sort(v.begin(), v.end());
    while(next_permutation(v.begin(), v.end())){
        pair<string, string> ant = {"73", "37"};
        int chg = 0;
        for(int i = 0; i < n; i++){
            if(ant.first == "73"){
                ant.first = v[i].first;
                ant.second = v[i].second;
            }else if(ant.first != v[i].first and ant.second != v[i].second){
                chg = INF;
                break;
            }else{
                ant.first = v[i].first;
                ant.second = v[i].second;
            }
        }
        ans = min(ans, chg);
    }
    for(int mask = 0; mask <= (1 << n); mask++){
        pair<string, string> ant = {"73", "37"};
        int chg = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                if(ant.first == "73"){
                    ant.first = v[i].first;
                    ant.second = v[i].second;
                }else if(ant.first != v[i].first and ant.second != v[i].second){
                    chg = INF;
                    break;
                }else{
                    ant.first = v[i].first;
                    ant.second = v[i].second;
                }
            }else chg++;
        }
        ans = min(ans, chg);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
