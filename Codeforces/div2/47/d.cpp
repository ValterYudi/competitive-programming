#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
bool is_valid(vector<string> &w, string s){
    int n = s.size();
    for(int i = 0; i < w.size(); i++){
        ll corrects = 0;
        for(int j = 0; j < n; j++){
            if(w[i][j] == s[j]){
                corrects++;
            }
        }
        if(corrects != (w[i][n] - '0')){
            return false;
        }
    }
    return true;
}

int testa(vector<string> &w, string s, int cgl, int pos){
    int n = s.size();
    if(cgl == 0 or pos == n){
        //cout << s << " " << cgl << " " << pos << " " << is_valid(w, s) << endl;
        return is_valid(w, s);
    }
    int ans = 0;
    ans += testa(w, s, cgl, pos+1);
    s[pos] = s[pos] == '0' ? '1' : '0';
    ans += testa(w, s, cgl-1, pos+1);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll ans = 0;
        vector<string> v(m);
        vi aux(m);
        for(int i = 0; i < m; i++){
            string s; cin >> s;
            char c; cin >> c;
            v[i] = s + c;
        }
        string otima = v[0];
        int maior = 0;
        for(int i = 0; i < m; i++){
            int aux = v[i][n] - '0';
            if(aux > maior){
                maior = aux;
                otima = v[i];
            }
            if(n - aux > maior){
                string nova = v[i];
                for(int j = 0; j < n; j++){
                    nova[j] = nova[j] == '0' ? '1' : '0';
                }
                otima = nova;
                maior = n - aux;
            }
        }
        otima.erase(otima.begin() + n);
        int cgl = n - maior;
        ans = testa(v, otima, cgl, 0);
        cout << ans << endl;
    }
}
