#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    string a, b, c; cin >> a >> b >> c;
    map<char, int> m;
    if(a[1] == '>'){
        m[a[0]]++;
    }else
        m[a[2]]++;
    if(b[1] == '>'){
        m[b[0]]++;
    }else
        m[b[2]]++;

    if(c[1] == '>'){
        m[c[0]]++;
    }else
        m[c[2]]++;

    if(m['A'] == m['B'] or m['A'] == m['C'] or m['B'] == m['C']){
        cout << "Impossible\n";
        return;
    }    

    if(m['A'] == 0){
        cout << "A";
    }else if(m['B'] == 0){
        cout << "B";
    }else if(m['C'] == 0){
        cout << "C";
    }

    if(m['A'] == 1){
        cout << "A";
    }else if(m['B'] == 1){
        cout << "B";
    }else if(m['C'] == 1){
        cout << "C";
    }

    if(m['A'] == 2){
        cout << "A";
    }else if(m['B'] == 2){
        cout << "B";
    }else if(m['C'] == 2){
        cout << "C";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
