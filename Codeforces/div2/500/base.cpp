#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

#define mp make_pair
#define F first
#define S second
#define dbg_v(x) for (auto i : x) cout << i << " "; cout << endl;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, x, mini = -1; cin >> n >> x;
    vi v(n), nd(n);
    map<int, int> aux;
    bool ok = false;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(aux.count(v[i]) == 0) aux[v[i]]++;
        else{
            ok = true;
        }
        nd[i] = v[i]&x;
    }
    if(ok){
        cout << 0 << endl;
        return 0;
    }
    bool check = false;
    set<int> s;
    for(int i = 0; i < n; i ++){
        if(s.count(nd[i]) == 0) s.insert(nd[i]);
        else check = true;
        if((nd[i] == v[i] && aux.count(nd[i]) > 1) || (nd[i] != v[i] && aux.count(nd[i]) > 0)){
            mini = 1;
        }
    }
    if(mini == 1) cout << 1 << endl;
    else if(check) cout << 2 << endl;
    else cout << -1 << endl;
    return 0;
}