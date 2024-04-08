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

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string line;
    vector<string> v;
    vector<vi> m;
	while(cin >> line){
        vector<int> aux;
        for(int i = 0; i < line.size(); i++){
            if(line[i] == '.'){
                aux.push_back(0);
            }else if(line[i] <='9' && line[i] >= '0'){
                int pos = i+1, num = (line[i] - '0');
                while((pos < line.size()) and (line[pos] <='9') && (line[pos] >= '0')){
                    num *= 10;
                    num += int(line[pos] - '0');
                    pos++;
                }
                for(int j = i; j < pos; j++){
                    aux.push_back(num);
                }
                i = pos-1;
            }else{
                aux.push_back(-1);
            }
        }
        m.push_back(aux);
    }

    ll ans = 0;
    int linhas = m.size(), colunas = m[0].size();
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < m[i].size(); j++){
            if(m[i][j] == -1){
                int adj = 0, sum = 1;
                for(int l=i-1; l<=i+1; l++){
                    int ant = 0;
                    for(int c=j-1; c<=j+1; c++){
                        if(c >= colunas or l >= linhas or l<0 or c <0) continue;
                        if(m[l][c] > 0 and ant <= 0){
                            sum *= m[l][c];
                            adj++;
                        }
                        ant = m[l][c];
                    }
                }
                if(adj == 2) ans += sum;
            }
        }
    }
    cout << ans << endl;
	return 0;
}
