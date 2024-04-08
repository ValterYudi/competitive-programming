#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()



struct ST{
	int size, def_value;
	vector<int> tree, lazy;

	ST(int n){
		size = n;
		def_value = 0;
		tree.resize(4*size, def_value);
		lazy.resize(4*size, def_value);
	}

	int query(int i, int j){
		return query(1, 0, size-1, i, j);
	}
	int query(int node, int l, int r, int L, int R){//L e R são os limites da query l e r representa o segmento que estamos olhando 
		if(lazy[node] != def_value){
			tree[node] += (r-l+1)*lazy[node];
			if(l != r){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = def_value;
		}
		if(R < l || r < L){ 
			return def_value;
		} 
		if(L <= l && r <= R){
			return tree[node];
		}
		int mid = (l+r)/2;
		int esq = query(node*2, l, mid, L, R);
		int dir = query(node*2+1, mid+1, r, L, R);
        return (esq + dir); // cópia da condição de merge
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
			tree[node] = tree[node*2] + tree[node*2+1];
        }	
	}

	void updateRange(int i, int j, int value){
		updateRange(1, 0, size-1, i, j, value);
	}

	void updateRange(int node, int l, int r, int L, int R, int value){
		if(lazy[node] != def_value){
			tree[node] += (r-l+1)*lazy[node];
			if(l != r){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			lazy[node] = def_value;
		}
		if(R < l || r < L){
			return;
		}
		if(L <= l && r <= R){
			tree[node] += (r-l+1)*value;
			if(l != r){
				lazy[node*2] += value;
				lazy[node*2+1] += value;
			}
			return;
		}
		int mid = (l+r)/2;
		updateRange(node*2, l, mid, L, R, value);
		updateRange(node*2+1, mid+1, r, L, R, value);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NUint);cout.tie(NUint);
    int t = 1;
    while(t--){
        int n, q; cin >> n >> q;
        ST seg(n);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            seg.update(i, x);
        }
        while(q--){
            int l, r; cin >> l >> r;
			if(l % 2){
				int rr, plus; cin >> rr >> plus;
				seg.updateRange(r-1, rr-1, plus);
			}else{
				cout << seg.query(r-1, r-1) << endl;
			}
        }
    }
}
