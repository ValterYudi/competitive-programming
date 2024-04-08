#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
#define mp(a, b) make_pair(a, b)

struct DSU {
    vector<vector<pair<int, int>>> pai;
    vector<vector<int>> tamanho, rank;
    int num_conjuntos;

    DSU(int n, int m){
        num_conjuntos = n * m;
        rank.assign(n, vector<int>(m, 0));
        pai.resize(n, vector<pair<int, int>>(m));
        tamanho.assign(n, vector<int>(m, 1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pai[i][j] = make_pair(i, j);
            }
        }
    }

    pair<int, int> encontrar_conjunto(pair<int, int> i){
        if(pai[i.first][i.second] == i){
            return i;
        }
        return pai[i.first][i.second] = encontrar_conjunto(pai[i.first][i.second]);
    }

    bool mesmo_conjunto(pair<int, int> i, pair<int, int> j){
        return encontrar_conjunto(i) == encontrar_conjunto(j);
    }

    void unir_conjuntos(pair<int, int> i, pair<int, int> j){
        if(!mesmo_conjunto(i, j)){
            num_conjuntos--;
            pair<int, int> x = encontrar_conjunto(i), y = encontrar_conjunto(j);
            if(rank[x.first][x.second] > rank[y.first][y.second]){
                pai[y.first][y.second] = x;
                tamanho[x.first][x.second] += tamanho[y.first][y.second];
            }
            else{
                pai[x.first][x.second] = y;
                tamanho[y.first][y.second] += tamanho[x.first][x.second];
                if(rank[x.first][x.second] == rank[y.first][y.second]){
                    rank[y.first][y.second]++;
                }
            }
        }
    }

    int num_conjuntos_disjuntos(){
        return num_conjuntos;
    }

    int tamanho_do_conjunto(pair<int, int> i){
        return tamanho[encontrar_conjunto(i).first][encontrar_conjunto(i).second];
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;
        int pile;
        bool res = false;
        vector<vi> v(n, vi(m, 0));  
        DSU dsu(n, m); 
        for(auto &i : v){
            for(auto &j : i){
                cin >> j;
            }
        }
        int big = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0 and v[i][j] != 0){
                    continue;
                }
                else if(i == 0 and v[i][j] != 0){
                    if(v[i][j-1] > 0){
                        dsu.unir_conjuntos(mp(i, j), mp(i, j-1));
                    }
                }
                else if(j == 0 and v[i][j] != 0){
                    if(v[i-1][j] > 0){
                        dsu.unir_conjuntos(mp(i, j), mp(i-1, j));
                    }
                }
                else if(v[i][j] != 0){
                    if(v[i][j-1] > 0){
                        dsu.unir_conjuntos(mp(i, j), mp(i, j-1));
                    }
                    if(v[i-1][j] > 0 and !(dsu.mesmo_conjunto(mp(i, j), mp(i-1, j)))){
                        dsu.unir_conjuntos(mp(i, j), mp(i-1, j));
                    }
                }
            }
        }
        map<ii, int> mp;
        //achar conjunto com a maior soma de valores em v
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] != 0){
                    mp[dsu.encontrar_conjunto(mp(i, j))] += v[i][j];
                    big = max(big, mp[dsu.encontrar_conjunto(mp(i, j))]);
                }
            }
        }
        cout << big << endl;
    }
}
