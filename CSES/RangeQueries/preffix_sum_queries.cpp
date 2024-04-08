#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define first F;
#define second S;

struct ST{
	int size, def_value, def_value_lazy;
	vector<int> tree, lazy;

	ST(int n){
		size = n;
		def_value = -1000000000;
        def_value_lazy = 0;
		tree.resize(4*size, def_value);
		lazy.resize(4*size, def_value_lazy);
	}

	int query(int i, int j){
		return query(1, 0, size-1, i, j);
	}
	int query(int node, int l, int r, int ql, int qr){//L e R são os limites da query l e r representa o segmento que estamos olhando 
		if(lazy[node] != def_value_lazy){
            if(tree[node] != def_value)
			    tree[node] += (r-l+1)*lazy[node];
            else
                tree[node] = (r-l+1)*lazy[node];
			if(l != r){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = def_value_lazy;
		}
		if(qr < l || r < ql){ 
			return def_value;
		} 
		if(ql <= l && r <= qr){
			return tree[node];
		}
		int mid = (l+r)/2;
		int esq = query(node*2, l, mid, ql, qr);
		int dir = query(node*2+1, mid+1, r, ql, qr);
        return max(esq, dir); // cópia da condição de merge
	}
	void update(int pos, int value){
		update(1, 0, size-1, pos, value);
	}
	void update(int node, int l, int r, int posicao, int value){
		if(l == r and l == posicao){
            tree[node] = value;
        }else{
            int mid = (l + r) / 2;
            if(l <= posicao and posicao <= mid){
                update(node*2, l, mid, posicao, value);
            }else{
                update(node*2+1, mid+1, r, posicao, value);
            }
            // aqui fica a condição de merge
			tree[node] = max(tree[node*2], tree[node*2+1]);
        }	
	}

	void updateRange(int i, int j, int value){
		updateRange(1, 0, size-1, i, j, value);
	}

	void updateRange(int node, int l, int r, int L, int R, int value){
		if(lazy[node] != def_value_lazy){
            if(tree[node] != def_value)
			    tree[node] += (r-l+1)*lazy[node];
            else
                tree[node] = (r-l+1)*lazy[node];
			if(l != r){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = def_value_lazy;
		}
		if(R < l || r < L){
			return;
		}
		if(L <= l && r <= R){
			if(tree[node] != def_value)
			    tree[node] += (r-l+1)*lazy[node];
            else
                tree[node] = (r-l+1)*lazy[node];
			if(l != r){
				lazy[node*2] += value;
				lazy[node*2+1] += value;
			}
			return;
		}
		int mid = (l+r)/2;
		updateRange(node*2, l, mid, L, R, value);
		updateRange(node*2+1, mid+1, r, L, R, value);
		tree[node] = max(tree[node*2], tree[node*2+1]);
	}
};

int main(){
    int n, q; cin >> n >> q;
    ST st(n);
    int soma = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
        soma += x;
        cout << soma << ' ';
        st.update(i, soma);
    }
    cout << '\n';

    while(q--){
        int tipo; cin >> tipo;
        if(tipo%2){
            int k, x; cin >> k >> x;
            int value = x - a[k-1];
            st.updateRange(k-1, n-1, value);
            for(int i = 0; i < n; i++){
                cout << st.query(i, i) << ' ';
            }
            cout << '\n';
        }else{
            int l, r; cin >> l >> r;
            if(l == 1)
                cout << st.query(l-1, r-1) << '\n';
            else
                cout << st.query(l-1, r-1) << " " << st.query(l-2, l-2) << '\n';
        }
    }
}