#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define MIN -1000000000
#define F first
#define S second

struct ST2D {
    vector<vector<int>> tree;
    int rows, cols;

    ST2D(int rows, int cols) : rows(rows), cols(cols) {
        tree.resize(4 * rows, vector<int>(4 * cols, 0));
    }

    void build_y(int vx, int vy, int tl, int tr, int x, vector<vector<int>>& matrix) {
        if (tl == tr) {
            // Constrói a árvore 1D na dimensão y
            tree[vx][vy] = matrix[tl][x];
        } else {
            int tm = (tl + tr) / 2;
            build_y(vx, vy * 2, tl, tm, x, matrix);
            build_y(vx, vy * 2 + 1, tm + 1, tr, x, matrix);
            tree[vx][vy] = tree[vx][vy * 2] + tree[vx][vy * 2 + 1];
        }
    }

    void build_x(int vx, int tl, int tr, vector<vector<int>>& matrix) {
        if (tl != tr) {
            int tm = (tl + tr) / 2;
            build_x(vx * 2, tl, tm, matrix);
            build_x(vx * 2 + 1, tm + 1, tr, matrix);
        }
        build_y(vx, 1, 0, cols - 1, vx, matrix);
    }

    void build(vector<vector<int>>& matrix) {
        build_x(1, 0, rows - 1, matrix);
    }

    int query_y(int vx, int vy, int tly, int try_, int ly, int ry) {
        if (ly > ry) return 0;
        if (tly == ly && try_ == ry) {
            // Consulta na árvore 1D na dimensão y
            return tree[vx][vy];
        }
        int tmy = (tly + try_) / 2;
        return query_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)) +
               query_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry);
    }

    int query_x(int vx, int tlx, int trx, int tly, int try_, int lx, int rx, int ly, int ry) {
        if (lx > rx) return 0;
        if (tlx >= lx && trx <= rx) {
            // Consulta na árvore 1D na dimensão x
            return query_y(vx, 1, tly, try_, ly, ry);
        }
        int tmx = (tlx + trx) / 2;
        return query_x(vx * 2, tlx, tmx, tly, try_, lx, min(rx, tmx), ly, ry) +
               query_x(vx * 2 + 1, tmx + 1, trx, tly, try_, max(lx, tmx + 1), rx, ly, ry);
    }

    int query(int lx, int rx, int ly, int ry) {
        return query_x(1, 0, rows - 1, 0, cols - 1, lx, rx, ly, ry);
    }

    void update_y(int vx, int vy, int tly, int try_, int y, int x, int value) {
        if (tly == try_) {
            // Atualização na árvore 1D na dimensão y
            tree[vx][vy] = value;
        } else {
            int tmy = (tly + try_) / 2;
            if (y <= tmy) {
                update_y(vx, vy * 2, tly, tmy, y, x, value);
            } else {
                update_y(vx, vy * 2 + 1, tmy + 1, try_, y, x, value);
            }
            tree[vx][vy] = tree[vx * 2][vy] + tree[vx * 2 + 1][vy];
        }
    }

    void update_x(int vx, int tlx, int trx, int x, int y, int value) {
        if (tlx != trx) {
            int tmx = (tlx + trx) / 2;
            if (x <= tmx) {
                update_x(vx * 2, tlx, tmx, x, y, value);
            } else {
                update_x(vx * 2 + 1, tmx + 1, trx, x, y, value);
            }
        }
        update_y(vx, 1, 0, cols - 1, y, x, value);
    }

    void update(int x, int y, int value) {
        update_x(1, 0, rows - 1, x, y, value);
    }
    void print(){
        for(int i=0; i<tree.size(); i++){
            for(int j=0; j<tree[i].size(); j++){
                cout << tree[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  
    //cin >> t; 
    
    while(t--){
        int n, q; cin >> n >> q;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                char aux; cin >> aux;
                if(aux == '*'){
                    a[i][j] = 1;
                }else{
                    a[i][j] = 0;
                }
            }
        }
        ST2D st_a(n, n);

        st_a.build(a);
        st_a.print();
        //cout << st_a.query(0, n-1, 0, n-1) << endl;
        while(q--){
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            int ans = st_a.query(x1, x2, y1, y2);
            cout << ans << endl;
        }
    }
    return 0;
}