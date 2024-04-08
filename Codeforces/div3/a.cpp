#include<bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> ii;

#define F first
#define S second
#define INF 1e18
struct ST{
    int size, def_value;
    vector<int> tree;
    vector<int> aux;
    
    ST(int n, vector<int> &v){
        size = n;
        def_value = 0;
        tree.resize(4*size, 0);
        aux.resize(4*size, 0);
        build(1, 0, size-1, v);
    }

    void build(int node, int l, int r, vector<int> &v){
        if(l == r){
            tree[node] = v[l];
        }else{
            int mid = (l+r)/2;
            build(node*2, l, mid, v);
            build(node*2+1, mid+1, r, v);
            // aqui fica a condição de merge
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }

    int query(int i, int j, int tipo){
        return query(1, 0, size-1, i, j, tipo);
    }
    int query(int node, int l, int r, int L, int R, int tipo){//L e R são os limites da query l e r representa o segmento que estamos olhando 
        if(R < l || r < L){ 
            return def_value;
        } 
        if(L <= l && r <= R){
            if(tree[node] == tipo * (r - l + 1)) return aux[node];
        }
        int mid = (l+r)/2;
        int esq = query(node*2, l, mid, L, R, tipo);
        int dir = query(node*2+1, mid+1, r, L, R, tipo);
        return (esq + dir);
    }
    void update(int pos, int value){
        update(1, 0, size-1, pos, value);
    }
    void update(int node, int l, int r, int posicao, int value){
        if(posicao < l || r < posicao){
            return;
        }
        if(l == r){
            tree[node] ^= value;
        }else{
            int mid = (l + r) / 2;
            if(l <= posicao and posicao <= mid){
                update(node*2, l, mid, posicao, value);
            }else{
                update(node*2+1, mid+1, r, posicao, value);
            }
            // aqui fica a condição de merge
            tree[node] = (tree[node*2] + tree[node*2+1]);
            aux[node] = (aux[node*2] xor aux[node*2+1]);
        }	
    }
};
void solve1() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto &a : v) cin >> a;
    ST st(n, v);
    string s; cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            st.update(i, 0);
        } else {
            st.update(i, 1);
        }
    }
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int l, r; cin >> l >> r;
            cout << st.update(l, r) << '\n';
        } else {
            int pos, val; cin >> pos >> val;
            if(val == 0) {
                st.update(pos, 0);
            } else {
                st.update(pos, 1);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t; while (t--) 
    solve1();
    
    
    return 0;
}