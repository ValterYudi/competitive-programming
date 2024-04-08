#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q; cin >> q;

    while(q--){
        int n; cin >> n;
        vi kids(n + 1);
        unordered_set<int> not_ans;
        for(int i = 1; i <= n; i++){
            cin >> kids[i];
            not_ans.insert(i);
        }
        int days, aux;
        for(int i = 1; i <= n and !not_ans.empty(); i++){
            days = 1, aux = kids[i];
            set<int> cycle;
            
            if(aux == i and not_ans.count(i)){
                cycle.insert(i);
                not_ans.erase(aux);
            }else if(not_ans.count(i)){
                cycle.insert(i);
                // checando quem está no ciclo, pois tamanho do ciclo define a resposta para os que estão no ciclo
                while(not_ans.count(aux) && aux != i){
                    cycle.insert(aux);
                    not_ans.erase(aux);
                    aux = kids[aux];
                    days++;
                }
                not_ans.erase(aux);
            }
            for(auto k : cycle){
                kids[k] = days;
            }

        }
        for(int i = 1; i < n; i++) cout << kids[i] << " ";
        cout << kids[n] << endl;
    }
    
}