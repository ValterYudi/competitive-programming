#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int valid(vii &v, int x, int y){
    if(max(x, y) > 8 or min(x, y) < 1) return 0;

    for(auto ele : v) if(make_pair(x, y) == ele) return 2;
    
    return 1;
}
void busca(vii &v_init, vector<vii> &ans){

    set<vii> aux, states = {v_init};
    for(int k = 0; k < 4; k++){// 4 passos
        for(auto& v: states){
            for(int l = 0; l < 4; l++){
                int x = v[l].first, y = v[l].second; 
                vii copia;
                for(int i = 0; i < 4; i++){// 4 direções
                    copia = v;
                    int nx = x + moves[i][0];
                    int ny = y + moves[i][1];

                    if(valid(copia, nx, ny) == 1){
                        copia[l].first = nx;
                        copia[l].second = ny;
                        aux.insert(copia);
                    }else if(valid(copia, nx, ny) == 2 and valid(copia, nx+moves[i][0], ny+moves[i][1]) == 1){
                        copia[l].first = nx + moves[i][0];
                        copia[l].second = ny + moves[i][1];
                        aux.insert(copia);
                    }
                }
            }
        }
        //add to ans
        states = aux;
        for(auto a : aux) ans.push_back(a);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        aux.clear();
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 0;
    cin >> t;
    while(t--){
        vii v_org(4), vf(4);
        for(auto &a : v_org) cin >> a.first >> a.second;
        for(auto &a : vf) cin >> a.first >> a.second;
        vector<vii> ans_init, ans_final;
        ans_init.push_back(v_org);
        ans_final.push_back(vf);
        busca(v_org, ans_init);
        busca(vf, ans_final);
        bool ok = 1;
        for(auto a : ans_init){
            // for(auto e : a) cout << e.first << " " << e.second << " \n"[e == a.back()];
            if(binary_search(ans_final.begin(), ans_final.end(), a)){
                cout << "YES\n";
                ok = 0;
            }
        }
        // for(auto a : ans_final) for(auto e : a) cout << e.first << " " << e.second << " \n"[e == a.back()];
        if(ok) cout << "NO\n";
    }
    return 0;
}
