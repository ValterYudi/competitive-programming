#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n; cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        string s;   cin >> s;
        mp[s]++;
    }
    string winner;
    int maior = 0;
    for(auto x: mp){
        if(x.second > maior){
            maior = x.second;
            winner = x.first;
        }
    }
    cout << winner << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    //int t = 1;  cin >> t; while(t--)
    solve1();
    
    return 0;
}