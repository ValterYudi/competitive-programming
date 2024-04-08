#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1000; 
    //cin >> t;
    ll f_ans = 0;
    map<string, int> m;
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';
    while(t--){
        string s; cin >> s;
        int n = s.size();
        ll ans = -1, num = 0;
        int left = 0, right = 0;
        for(int i=0; i<n; i++){
            if((s[i] >= '0' and s[i] <= '9')){
                num = ll(s[i]) - ll('0');
                if(ans == -1){
                    ans = num*10;
                    left = i;
                }
                right = i;
            }
        }
        ans += num;
        string s1 = s.substr(0, left);
        string s2 = s.substr(right+1, n-1-right);
        if(s1.size()){
            string f = "";
            int tam = s1.size();
            for(int l=0; l<tam; l++){
                for(int r=l+2; r<min(l+6,tam); r++){
                    string aux = s1.substr(l, r-l+1);
                    if(m.find(aux) != m.end()){
                        f = m[aux];
                        l = r;
                        break;
                    }
                }
                if(f != "") break;
            }
            if(f != ""){
                ans = ll(f[0] -'0')*10;
                ans += num;
            }
        }
        if(s2.size()){
            reverse(s2.begin(), s2.end());
            string f = "";
            int tam = s2.size();
            for(int l=0; l<tam; l++){
                for(int r=l+2; r<min(l+6,tam); r++){
                    string aux = s2.substr(l, r-l+1);
                    reverse(aux.begin(), aux.end());
                    cout << aux << endl;
                    if(m.find(aux) != m.end()){
                        f = m[aux];
                        l = r;
                        break;
                    }
                }
                if(f != "") break;
            }
            if(f != ""){
                ans -= num;
                ans += ll(f[0] -'0');
            }
        }
        f_ans += ans;
    }
    cout << f_ans << endl;
}