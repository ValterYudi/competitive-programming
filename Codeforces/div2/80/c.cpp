#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

struct DSU{
    vi pai, peso;

    DSU(int n){
        pai.resize(n + 5);
        for(int i = 1; i <= n;i++) pai[i] = i;
        peso.resize(n + 5, 0);
    }

    int find(int x){
        if(pai[x]==x) return x;

        return pai[x] = find(pai[x]);
    }
    void join(int x, int y){

        x = find(x);
        y = find(y);
        if(x==y)
            return;

        if(peso[x] > peso[y]){
            pai[y]=x;
        }else if(peso[x] < peso[y]){
            pai[x]=y;
        }
        else{
            pai[y]=x;
            peso[x]++;
        }

    }
};

void solve(){
    int n, m; cin >>n >> m;
    if(n == m){
        int cycle = 0;
        DSU chulu(n);
        while(m--){
            int l, r; cin >> l >> r;
            if(chulu.find(l) == chulu.find(r)){
                cycle++;
            }else{
                chulu.join(l, r);
            }
        }
        if(cycle == 1){
            cout << "FHTAGN!\n";
        }else cout << "NO\n";
    }
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
