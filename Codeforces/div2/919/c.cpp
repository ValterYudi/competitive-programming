#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define MIN -1000000000
#define F first
#define S second
struct SegmentTree {
    vi tree;
    int n;

    SegmentTree(int n) : n(n) {
        tree.resize(2 * n);
    }

    void build(vi& a) {
        for (int i = 0; i < n; i++)
            tree[n + i] = a[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = __gcd(tree[i<<1], tree[i<<1|1]);
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = __gcd(res, tree[l++]);
            if (r&1) res = __gcd(res, tree[--r]);
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  
    cin >> t; 
    
    while(t--){
        int n; cin >> n;
        vi v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        SegmentTree st(n);
        st.build(v);
        cout << "olha o vetor:" << endl;
        for(int i = 1; i <= sqrt(n); i++){
            if (n % i == 0) {
                //make queries on the segtree for each multiple of i in the range [1, n]
                for(int j = 0; j < n; j+=i){
                    cout << st.query(j, j+i) << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
