#include <bits/stdc++.h>

using namespace std;

struct ST{
    vector<int> tree;
    int size = 0;
    int def_value = 0;

    ST(int n, int def = 0){
        def_value = def;
        size = n;
        tree.resize(n*4, 0);
    }

    void build(vector<int> &v, int node, int l, int r){
        if(l == r){
            tree[node] = v[l];
        }else{
            int mid = (l+r)/2;
            build(v, node*2, l, mid);
            build(v, node*2+1, mid + 1, r);
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }

    int query(int ql, int qr){
        return query(1, 0, size-1, ql, qr);
    }

    int query(int node, int l, int r, int ql, int qr){
        if(qr < l or r < ql){
            return def_value;
        }
        if(ql <= l and r <= qr){
            return tree[node];
        }
        int mid = (l+r)/2;
        int esq = query(node*2, l, mid, ql, qr);
        int dir = query(node*2+1, mid+1, r, ql, qr);

        return esq + dir;
    }

    void update(int pos, int value){
        update(1, 0, size-1, pos, value);
    }

    void update(int node, int l, int r, int pos, int value){
        if(l == r){
            tree[node] = value;
        }else{
            int mid = (l+r)/2;
            if(pos <= mid){
                update(node*2, l, mid, pos, value);
            }else{
                update(node*2+1, mid+1, r, pos, value);
            }
            tree[node] = tree[node*2] + tree[node*2+1];
        }
    }
};

int main(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(auto &a : v) cin >> a;
    ST st(n, 0);
    st.build(v, 1, 0, n-1);
    while(q--){
        int tipo; cin >> tipo;
        if(tipo == 1){
            int l, r; cin >> l >> r;
            l--; r--;
            int ans = st.query(l, r);
            cout << ans << endl;
        }else{
            int pos, value; cin >> pos >> value;
            pos--;
            st.update(pos, value);
        }
    }
}