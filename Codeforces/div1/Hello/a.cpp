#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define MIN -1000000000
#define F first
#define S second

void solve(){
    int n; cin >> n;
    int ant = 1000000000, soma = 0;
    //receiving a vector, what is the best way to split 2 subsequnces of this vector, in order that the number os increasing adjacents is minimized?
    vector<ii> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].F;
        v[i].S = i;
    }
    sort(v.begin(), v.end(), greater<ii>());
    for(int i = 1; i < n; i++){
        if(!(v[i].F == v[i-1].F and abs(v[i].S - v[i-1].S) == 1) && (v[i].S < v[i-1].S)){
            soma++;
        }
    }
    if(soma == 0){
        cout << 0 << endl;
    }else{
        cout << soma-1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1; cin >> t; while(t--)
        solve();

    return 0;
}
