#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

bool check_str_num(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] < '0' or s[i] > '9') return false;
    }
    if(s.size() > 1 and s[0] == '0') return false;
    return true;
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t; 
    bool vazio = false;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        map<char, int> m;
        for(int i = 0; i < n; i++){
            m[s[i]]++;
        }
        string changes = "";
        char prim = '*';
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second % 2 == 1){
                changes += it->first;
            }
        }
        if(n%2){
            prim = changes[changes.size()/2];
            m[changes[changes.size()/2]]--;
            changes.erase(changes.begin() + changes.size()/2);
        }
        int tam = changes.size();
        for(int i = 0; i < (tam/2); i++){
            m[changes[tam - i - 1]]--;
            m[changes[i]]++;
        }
        string ans = "", ans2= "";
        for(auto it = m.rbegin(); it != m.rend(); it++){
            int aux = it->second;
            while(aux > 0){
                if(aux % 2) ans += it->first;
                else ans2 += it->first;
                aux--;
            }
        }
        reverse(ans.begin(), ans.end());
        if(prim != '*') ans += prim;
        ans += ans2;
        cout << ans << endl;
    }
}