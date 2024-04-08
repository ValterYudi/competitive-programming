#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

struct ST{
    vector<int> tree;
    int size = 0;
    int def_value = 0;

    ST(int n, int def = 0){
        def_value = def;
        size = n;
        tree.resize(n*4, def);
    }
    void build(vi &v){
        build(v, 1, 0, size-1);
    }

    void build(vector<int> &v, int node, int l, int r){
        if(l == r){
            tree[node] = v[l];
        }else{
            int mid = (l+r)/2;
            build(v, node*2, l, mid);
            build(v, node*2+1, mid + 1, r);
            tree[node] = min(tree[node*2], tree[node*2+1]);
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

        return min(esq , dir);
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
            tree[node] = min(tree[node*2], tree[node*2+1]);
        }
    }

    int query_bin(int l, int r, int n){
        int mid = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(query(mid, r) < n) l = mid+1;
            else r = mid - 1;
        }
        return query(r, r);
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        int n; cin >> n;
        ST mini(n, 1e9);
        vi v(n);
        map<int, int> lst;
        int index = 0;
        for(auto &a : v){
            cin >> a;
            lst[a] = index;
            index++;
        }

        mini.build(v);
        for(int i = 0; i < n-1; i++){
            int atual = v[i];
            int m = mini.query_bin(i+1, n-1, atual);
            if(m >= atual) cout << "-1 ";
            else cout << lst[m] - i - 1 << ' ';
        }
        cout << "-1\n";
    }
}
