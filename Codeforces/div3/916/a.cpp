#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> m;
    for(auto c : s){
        m[c]++;
    }
    int count = 0;
    for(auto p : m){
        int check = int(p.first - 'A') + 1;
        if(check <= p.second){
            count++;
        }
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}