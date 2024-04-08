#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

bool differs(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) cnt++;
        if(cnt > 1) return true;
    }
    return false;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<int> divs;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            divs.insert(i);
            if(i != n/i) divs.insert(n/i);
        }
    }
    for(int d : divs){
        for(int ini = 0; ini <= 1; ini++){
            string k = s.substr(ini*d, d);
            bool ok = true, difou = false;
            for(int i = 1^ini; i < n/d; i++){
                string t = s.substr(i*d, d);
                if(t != k){
                    if(differs(t, k)){
                        difou = true;
                        break;
                    }
                    if(!ok) difou = true;
                    ok = false;
                }
            }
            if(!difou){
                cout << d << endl;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
