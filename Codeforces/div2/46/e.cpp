#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    string a, b; cin >> a >> b;
    int n; cin >> n;
    vector<string> m;
    while(n--){
        char valor, dsc; cin >> valor >> dsc >> dsc;
        string chave; cin >> chave;
        m.push_back(chave+valor);
    }
    vector<string> states, ans1, ans2;
    states.push_back(a);
    ans1.push_back(a);
    while(!states.empty()){
        set<string> aux;
        for(auto e: m){
            string key = e.substr(0, 2);
            char value = e[2];
            for(int i = 0; i < states.size(); i++){
                for(int j = 0; j < states[i].size(); j++){
                    if(states[i].substr(j, 2) == key){
                        string aux_state = states[i];
                        aux_state.replace(j, 2, 1, value);
                        aux.insert(aux_state);
                    }
                }
            }
        }
        states.clear();
        for(auto state : aux){
            ans1.push_back(state);
            states.push_back(state);
        }
        ans1.erase(unique(ans1.begin(), ans1.end()), ans1.end());
    }

    states.clear();
    states.push_back(b);
    ans2.push_back(b);
    while(!states.empty()){
        set<string> aux;
        for(auto e: m){
            string key = e.substr(0, 2);
            char value = e[2];
            for(int i = 0; i < states.size(); i++){
                for(int j = 0; j < states[i].size(); j++){
                    if(states[i].substr(j, 2) == key){
                        string aux_state = states[i];
                        aux_state.replace(j, 2, 1, value);
                        aux.insert(aux_state);
                    }
                    
                }
            }
        }
        states.clear();
        for(auto state : aux){
            ans2.push_back(state);
            states.push_back(state);
        }
        ans2.erase(unique(ans2.begin(), ans2.end()), ans2.end());
    }
    //intersection of ans1 and ans2
    int ans = 1000000000;
    for(auto state : ans1){
        if(find(ans2.begin(), ans2.end(), state) != ans2.end()){
            ans = min(ans, (int)state.size());
        }
    }
    if(ans == 1000000000){
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
