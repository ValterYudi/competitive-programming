#include<bits/stdc++.h>

#define INF 1e9
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    int n; cin >> n;
    map<string, set<string>> ga, ag;
    for(int i = 0; i < n; i++){
        string s1, s2; cin >> s1 >> s2;
        ga[s1].insert(s2);
        ag[s2].insert(s1);
    }
    vector<string> v;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
