#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n; cin >> n;
    vi v(n);
    for(auto &a : v) cin >> a;
    map<int, queue<char>> mpq;
    char c = 'a';
    string ans = "";
    for(int i = 0; i < n; i++){
        if(v[i] > 0){
            char aux = mpq[v[i]].front();
            ans += aux;
            mpq[v[i]].pop();
            mpq[v[i] + 1].push(aux);
        }else{
            mpq[1].push(c);
            ans += c;
            c++;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}