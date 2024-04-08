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
        vector<vector<char>> v(8, vector<char>(8));
        string s = "";
        for(auto &a: v){
            for(auto &b: a){
                cin >> b;
                if(b != '.') s += b;
            }
        }
        cout << s << endl;

    }
}