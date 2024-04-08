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
        string s1, s2; cin >> s1 >> s2;
        map<char, vi> occ;
        for(int i = 0; i < s1.size(); i++){
            occ[s1[i]].push_back(i);
        }
        int ant  = -1, ans = 1;
        for(int j = 0; j < s2.size(); j++){
            if(!occ.count(s2[j])){
                cout << -1 << endl;
                return 0;
            }

        }

    }
}
