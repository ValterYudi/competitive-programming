#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        string s; cin >> s;
        int pos; cin >> pos;
        string aux = s, ant = s;
        for(int i = 0; i < ant.size();){
            while(ant[i]  < ant[i + 1] and i < ant.size() - 1){
                i++;
            }
            ant = ant.substr(0, i) + ant.substr(i + 1, ant.size());
            //cout << ant << "\n";
            aux += ant;
            if(aux.size() >= pos) break;
        }
        //cout << aux << "\n";
        //cout << ant << "\n";
        while(ant.size() > 0){
            ant = ant.substr(0, ant.size() - 1);
            aux += ant;
            if(aux.size() >= pos) break;
        }
        //cout << aux << "\n";
        // cout << aux << "\n";
        cout << aux[--pos];
    }
}