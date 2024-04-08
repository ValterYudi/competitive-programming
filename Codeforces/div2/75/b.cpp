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
        string s; cin >> s;
        int ans = s.size()-1;
        bool ant = 0;
        for(int i = s.size()-1; i >= 1; i--){
            if(s[i] == '1' and !ant){
                ans++;
                ant = 1;
            }else if(ant and s[i] == '0') ans++;
        }
        if(ant) ans++;
        cout << ans << endl;
    }
}
