#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n; cin >> n;
    string s; cin >> s;
    int cont = 0;
    if(n >= 5){
        for(int i = 2; i < n - 2; i++){
            if(s[i-2] == 'm' and s[i-1] == 'a' and s[i] == 'p' and s[i+1] == 'i' and s[i+2] == 'e'){
                cont++;
                s[i] = 'x';
            }
        }
    }
    
    for(int i = 1; i < n - 1; i++){
        if(s[i-1] == 'm' and s[i] == 'a' and s[i+1] == 'p'){
            cont++;
        }else if(s[i-1] == 'p' and s[i] == 'i' and s[i+1] == 'e'){
            cont++;
        }
    }
    cout << cont << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}