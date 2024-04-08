#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int valid(vii &v, int x, int y){
    if(x < 1 || x > 8 || y < 1 || y > 8) return 0;

    if(make_pair(x, y) == v[0] || make_pair(x, y) == v[1] || make_pair(x, y) == v[2] || make_pair(x, y) == v[3]) return 2;
    
    return 1;
}
void busca(vii &v_init, vector<vii> &ans){

    vector<vii> aux, states(1, v_init);
    for(int k = 0; k < 4; k++){// 4 passos
        for(auto& v: states){
            for(auto& [x, y] : v){ 
                for(int i = 0; i < 4; i++){// 4 direções

                    int nx = x + moves[i][0];
                    int ny = y + moves[i][1];

                    if(valid(v, nx, ny) == 1){
                        x = nx;
                        y = ny;
                        aux.push_back(v);
                        x -= moves[i][0];
                        y -= moves[i][1];
                    }else if(valid(v, nx, ny) == 2 and valid(v, nx+moves[i][0], ny+moves[i][1]) == 1){
                        x = nx + moves[i][0];
                        y = ny + moves[i][1];
                        aux.push_back(v);
                        y -= moves[i][1]*2;
                        x -= moves[i][0]*2;
                    }

                }
                
            }
            sort(aux.begin(), aux.end());
            aux.erase(unique(aux.begin(), aux.end()), aux.end());
            swap(aux, states);
            //add to ans
            for(auto a : states) ans.push_back(a);
            aux.clear();
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
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
        for(auto a : ans_init){
            if(binary_search(ans_final.begin(), ans_final.end(), a)){
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
    }
    return 0;
}
