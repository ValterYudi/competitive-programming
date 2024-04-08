#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define mp make_pair
#define F first
#define S second


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;

    while(t--){
        int n, m, x, y; cin >> n >> m;
        vector<ii> adj;
        map<int, int> cont;
        set<int> folhas;
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            adj.push_back(mp(u, v));
            cont[u]++;
            cont[v]++;
            folhas.insert(u);
            folhas.insert(v);
            if(cont[u] > 2){
                folhas.erase(u);
            }
            if( cont[v] > 2){
                folhas.erase(v);
            }
        }
        set<int> galhos;
        for(int i = 0; i < m; i++){
            if(folhas.find(adj[i].first) != folhas.end()){
                galhos.insert(adj[i].second);
                y = cont[adj[i].second] - 1;
            }else if(folhas.find(adj[i].second) != folhas.end()){
                galhos.insert(adj[i].first);
                y = cont[adj[i].first] - 1;
            }
        }
        x = galhos.size();
        cout << x << " " << y << endl;
    }
}