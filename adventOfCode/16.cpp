#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long          ll;
typedef long double        ld;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;
 
#define mp make_pair
#define F first
#define S second
int visited[111][111][4];
// 0 - direita
// 1 - baixo
// 2 - esquerda
// 3 - cima
int percorre_grid(vector<string> &m, int i, int j, int dir){
    int linhas = m.size(), colunas = m[0].size();
    if (i < 0 or j < 0 or i >= linhas or j >= colunas) return 0;
    if (visited[i][j][dir]) return 0;
    int ans = (m[i][j] != '#') ? 1 : 0;
    visited[i][j][dir] = 1;
    if(m[i][j] != '.' and m[i][j] != '#'){
        for(int k = 0; k < 4; k++){
            if(k == dir) continue;
            if(visited[i][j][k]) ans = 0;
        }
    }
    // cout << "Estou na posicao " << i << " " << j << " e dir = " << dir << " e ans = " << ans << endl;
    if(m[i][j] == '.' or m[i][j] == '#'){
        m[i][j] = '#';
        if(dir == 0){
            j = j+1;
        }else if(dir == 1){
            i = i+1;
        }else if(dir == 2){
            j = j-1;
        }else{
            i = i-1;
        }
        ans += percorre_grid(m, i, j, dir) ;
    }else if(m[i][j] == '/'){
        if(dir == 0){
            dir = 3;
            i = i-1;
        }else if(dir == 1){
            dir = 2;
            j = j-1;
        }else if(dir == 2){
            dir = 1;
            i = i+1;
        }else{
            dir = 0;
            j = j+1;
        }
        ans += percorre_grid(m, i, j, dir) ;
    }else if(m[i][j] == '\\'){
        if(dir == 0){
            dir = 1;
            i = i+1;
        }else if(dir == 1){
            dir = 0;
            j = j+1;
        }else if(dir == 2){
            dir = 3;
            i = i-1;
        }else{
            dir = 2;
            j = j-1;
        }
        ans += percorre_grid(m, i, j, dir) ;
    }else if(m[i][j] == '-'){
        if(dir == 0){
            j = j+1;
            ans += percorre_grid(m, i, j, dir) ;
        }else if(dir == 2){
            j = j-1;
            ans += percorre_grid(m, i, j, dir) ;
        }
        else{
            ans += percorre_grid(m, i, j+1, 0);
            ans += percorre_grid(m, i, j-1, 2);
        }
    }else if(m[i][j] == '|'){
        if(dir == 1){
            i = i+1;
            ans += percorre_grid(m, i, j, dir) ;
        }else if(dir == 3){
            i = i-1;
            ans += percorre_grid(m, i, j, dir) ;
        }
        else{
            ans += percorre_grid(m, i+1, j, 1);
            ans += percorre_grid(m, i-1, j, 3);
        }
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string line;
    vector<string> m, aux;
	while(cin >> line){
        m.push_back(line);
    }
    int ans = 0;
    vi edges = {0, 109};
    for(auto i : edges){
        for(int j = 0; j < m[i].size(); j++){
            if(i == 0){
                if(j == 0){
                    memset(visited, 0, sizeof visited);
                    aux = m;
                    int ans_ij = percorre_grid(aux, i, j, 0);
                    ans = max(ans, ans_ij);
                }else if (j == m[i].size()-1){
                    memset(visited, 0, sizeof visited);
                    aux = m;
                    int ans_ij = percorre_grid(aux, i, j, 2);
                    ans = max(ans, ans_ij);
                }else{
                    memset(visited, 0, sizeof visited);
                    aux = m;
                    int ans_ij = percorre_grid(aux, j, i, 0);
                    ans = max(ans, ans_ij);
                }
                memset(visited, 0, sizeof visited);
                aux = m;
                int ans_ji = percorre_grid(aux, i, j, 1);
                ans = max(ans, ans_ji);

            }else{
                if(j == 0){
                    memset(visited, 0, sizeof visited);
                    aux = m;
                    int ans_ij = percorre_grid(aux, i, j, 0);
                    ans = max(ans, ans_ij);
                }else if (j == m[i].size()-1){
                    memset(visited, 0, sizeof visited);
                    aux = m;
                    int ans_ij = percorre_grid(aux, i, j, 2);
                    ans = max(ans, ans_ij);
                }else{
                    memset(visited, 0, sizeof visited);
                    aux = m;
                    int ans_ij = percorre_grid(aux, j, i, 2);
                    ans = max(ans, ans_ij);
                }
                memset(visited, 0, sizeof visited);
                aux = m;
                int ans_ji = percorre_grid(aux, i, j, 3);
                ans = max(ans, ans_ji);
            }
        }
    }

    cout << ans << endl;
	return 0;
}
