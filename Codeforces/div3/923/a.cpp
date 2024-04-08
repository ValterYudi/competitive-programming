#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve(){
    ll n; cin >> n;
    string s;   cin >> s;
    int p_b = -1, l_b;
    for(int i = 0; i < n ; i++){
        if(s[i] == 'B' and p_b == -1) p_b = i;
        if(s[i] == 'B') l_b = i;
    }
    cout << (l_b - p_b + 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve();
    
    return 0;
}