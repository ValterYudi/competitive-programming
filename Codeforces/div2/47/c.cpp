#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        vector<pair<int, string>> v(6);
        for(int i = 0; i < 6; i++){
            cin >> v[i].second;
            v[i].first = (v[i].second).size();
        }
        sort(v.begin(), v.end());
        vector<string> brd(4);
        for(int i = 0; i < 4; i++){
            brd[i] = v[i].second;
        }
        map<string, vector<string>> pri, ult;
        for(int i = 0; i < 4; i++){
            for(int j = i; j < 4; j++){
                if(brd[i][0] == brd[j][0]){
                    pri[brd[i]].push_back(brd[j]);
                }
            }
        }
        
        
    }
}
