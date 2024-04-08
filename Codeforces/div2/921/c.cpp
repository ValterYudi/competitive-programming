#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

bool ehPalindromo(const string& s) {
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        int n, k, m; cin >> n >> k >> m;
        string s; cin >> s;
        map<char, int> mp;
        for(char c : s) mp[c]++;
        int menor = 1e9;
        char menorChar;
        for(auto it : mp){
            menor = min(menor, it.second);
            if(menor == it.second) menorChar = it.first;
        }
        if(menor >= k){
            if(ehPalindromo(s)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
                for(int i = 0; i < k; i++) cout << menorChar;
                cout << endl;
            }
        }else{
            cout << "NO" << endl;
            for(int i = 0; i < k; i++) cout << menorChar;
            cout << endl;
        }
    }
}
