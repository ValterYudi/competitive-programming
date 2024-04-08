#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vi v(n);
        for(auto &i : v) cin >> i;
        ll soma = 0;
        set<int> uns; //set para posicoes que tem 1
        for(int i = 0; i < n; i++){
            soma += v[i];
            if(v[i] == 1) uns.insert(i);
        }
        while(q--){
            int tipo; cin >> tipo;
            if(tipo == 1){
                int target; cin >> target;
                if(target <= soma and (abs(soma - target) % 2 == 0)){ // case they are same parity it is always possible to decrease 2 from soma
                    cout << "YES" << endl;
                }else if (target <= soma){ // case they are different parity
                    if(uns.size() > 0){ // if there is a 1
                        int ini = *uns.begin(), fim = *uns.rbegin();
                        int tira_ini = soma - (ini*2) - 1, tira_fim = soma - ((n-fim-1)*2) - 1;
                        if(max(tira_ini, tira_fim) >= target) cout << "YES" << endl; // get the max of the two possible values to decrease
                        else cout << "NO" << endl;
                    }else{
                        cout << "NO" << endl;
                    }
                    
                }else{
                    cout << "NO" << endl;
                }
            }else{
                int pos, val; cin >> pos >> val;
                pos--;
                if(v[pos] == 1 and val != 1) uns.erase(pos);
                else if(v[pos] != 1 and val == 1) uns.insert(pos);
                soma += (val - v[pos]);
                v[pos] = val;
            }
        }

    }
    return 0;
}