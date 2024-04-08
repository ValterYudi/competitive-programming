#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

struct SegTree{
    int n;
    vector<ll> st;
    SegTree(int n){
        this->n = n;
        st.assign(4*n, 0);
    }
    ll query(int l, int r){
        return query(1, 0, n-1, l, r);
    }
    ll query(int p, int tl, int tr, int l, int r){
        if(l > r) return 0;
        if(l == tl && r == tr) return st[p];
        int tm = (tl + tr)/2;
        return query(2*p, tl, tm, l, min(r, tm)) + query(2*p+1, tm+1, tr, max(l, tm+1), r);
    }
    void update(int i, int v){
        update(1, 0, n-1, i, v);
    }
    void update(int p, int tl, int tr, int i, int v){
        if(tl == tr) st[p] += v;
        else{
            int tm = (tl + tr)/2;
            if(i <= tm) update(2*p, tl, tm, i, v);
            else update(2*p+1, tm+1, tr, i, v);
            st[p] = st[2*p] + st[2*p+1];
        }
    }
};

ll binary_search(int l, int r, SegTree &st, ll k){
    while(l < r){
        int m = (l + r)/2;
        if(st.query(0, m) >= k) r = m;
        else l = m + 1;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        a
    }
}