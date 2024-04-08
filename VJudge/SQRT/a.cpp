#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vi> g(n+1);
    set<int> on;
    int n_on = 0; cin >> n_on;
    while(n_on--){
        int user; cin >> user;
        on.insert(user);
    }
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(q--){
        char tipo; cin >> tipo;
        if(tipo == 'O'){
            int user; cin >> user;
            on.insert(user);
        }else if(tipo == 'F'){
            int user; cin >> user;
            on.erase(user);
        }else if(tipo == 'A'){
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }else if(tipo == 'D'){
            int u, v; cin >> u >> v;
            g[u].erase(find(g[u].begin(), g[u].end(), v));
            g[v].erase(find(g[v].begin(), g[v].end(), u));
        }else if(tipo == 'C'){
            int u, ans = 0; cin >> u;
            for(int v : g[u]){
                if(on.count(v)){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
