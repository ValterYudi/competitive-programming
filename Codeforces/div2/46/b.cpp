#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        string s = to_string(a) + to_string(b), aux_a = to_string(a), aux_b = to_string(b);
        
        int n = aux_b.size();
        while(aux_a.size() < n){
            aux_a = "0" + aux_a;
        }
        int maior = -10000000;
        for(int i = 0; i < s.size(); i++){
            if(s[i] - '0' > maior){
                maior = s[i] - '0';
            }
        }
        int base = maior + 1;
        int ans = 0, ant = 0;
        for(int i = n-1; i >= 0; i--){
            if(aux_a[i] - '0' + aux_b[i] - '0' + ant >= base){
                ant = 1;
            }else{
                ant = 0;
            }
            ans++;
        }
        if(ant > 0){
            ans++;
        }
        cout << ans << endl;
    }
}
