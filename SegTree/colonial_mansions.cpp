#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


struct ST{
    int size, def_value;
    vector<int> tree;
    
    ST(int n){
        size = n;
        def_value = -1;
        tree.resize(4*size, 0);
    }

    int query(int i, int j){
        return query(1, 0, size-1, i, j);
    }
    int query(int node, int l, int r, int L, int R){//L e R são os limites da query l e r representa o segmento que estamos olhando 
        if(R < l || r < L){ 
            return def_value;
        } 
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l+r)/2;
        int esq = query(node*2, l, mid, L, R);
        int dir = query(node*2+1, mid+1, r, L, R);
        return max(esq, dir);
    }
    void update(int pos, int value){
        update(1, 0, size-1, pos, value);
    }
    void update(int node, int l, int r, int posicao, int value){
        if(posicao < l || r < posicao){
            return;
        }
        if(l == r){
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
    int query_find(int pos, int value) {
        // binary search to find the maximum range <= value with pos in it
        int l = pos, r = size - 2, ans_r = pos, ans_l = pos;
        while (l <= r) {
            int mid = (l + r) / 2;
            int right = query(pos, mid);
            if (right >=0 and right <= value) {
                //cout << "!!!!!! right: " << right << " ans_r: " << ans_r << " mid: " << mid << " value: " << value << endl;
                ans_r = mid+1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
                //cout << "right: " << right << " ans_r: " << ans_r << " mid: " << mid << endl;
        }
        if(pos == 0) {
            //cout << "!!! ans_l: " << ans_l << " ans_r: " << ans_r << endl;
            return ans_r + 1;
        }
        l = 0, r = pos-1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int left = query(mid, pos-1);
            if (left >= 0 and left <= value) {
                ans_l = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        //cout << "ans_l: " << ans_l << " ans_r: " << ans_r << endl;
        return ans_r - ans_l + 1;
    }
    void printar_seg(){
        for(int i = 0; i < 2*size+1; i++){
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        ST dif(n);
        vi v(n);
        for (auto &le : v) cin >> le;

        for (int i = 0; i < n - 1; i++) {
            int aux = abs(v[i] - v[i + 1]);
            dif.update(i, aux);
        }
        while (q--) {
            int tipo, l, r;
            cin >> tipo >> l >> r;
                l--; // 0-based indexing
            if (tipo == 1) {
                v[l] = r;
				if(l - 1 >= 0){
					// update for the previous element
					dif.update(l-1, abs(v[l] - v[l-1]));
				}
				if(l < n - 1){
					// update for the next element
					dif.update(l, abs(v[l] - v[l+1]));
				}
            } else {
                //dif.printar_seg();
                int ans = dif.query_find(l, r);
                cout << ans << endl;
            }
        }
    }
}
