#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

//implement a segtree de minimos
typedef struct ST{
    int n;
    vector<int> st;
    ST(int n){
        this->n = n;
        st.assign(4*n, 0);
    }

    void update(int p, int l, int r, int i, int v){
        if(i < l || i > r) return;
        if(l == r){
            st[p] = v;
            return;
        }
        int mid = (l+r)/2;
        update(2*p, l, mid, i, v);
        update(2*p+1, mid+1, r, i, v);
        st[p] = min(st[2*p], st[2*p+1]);
    }

    int query(int p, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return INT_MAX;
        if(ql <= l && qr >= r) return st[p];
        int mid = (l+r)/2;
        return min(query(2*p, l, mid, ql, qr), query(2*p+1, mid+1, r, ql, qr));
    }
} ST;


void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n-1);
    int maior = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] > a[maior]) maior = i;
    }
    ST seg(n);
    for(int i=0; i<n-1; i++){
        cin >> b[i];
        seg.update(1, 0, n-1, i, b[i]);
    }
    int l = maior, r = maior;
    while(l >= 0 || r <= n-1){
        int q = seg.query(1, 0, n-1, l, r);
        
    }

}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t; while(t--)
    solve();
}