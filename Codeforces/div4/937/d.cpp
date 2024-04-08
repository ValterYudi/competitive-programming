#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

bool check_binary(int n){
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '0' && s[i] != '1') return false;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    queue<int> divs;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            if(check_binary(i) and check_binary(n/i)){
                cout << "YES" << endl;
                return;
            }
            if(check_binary(i)and i !=1){
                divs.push(n/i);
            }
            if(check_binary(n/i)){
                divs.push(i);
            }
        }
    }
    while(!divs.empty()){
        int aux = divs.front();
        divs.pop();
        for(int j = 10; j*j <= aux; j++){
            if(aux%j == 0){
                if(check_binary(j) and check_binary(aux/j)){
                    cout << "YES" << endl;
                    return;
                }
                if(check_binary(j)){
                    divs.push(aux/j);
                }
                if(check_binary(aux/j)){
                    divs.push(j);
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
