#include <vector>

using namespace std;

const int MAXN = 1e3+5;  // adjust this value as needed

struct SegTree2D {
    vector<vector<int>> t;
    vector<vector<int>> a;
    int n, m;

    SegTree2D(int n, int m) : n(n), m(m) {
        t.resize(4 * n, vector<int>(4 * m, 0));
        a.resize(n, vector<int>(m, 0));
    }

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx)
                t[vx][vy] = a[lx][ly];
            else
                t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
        } else {
            int my = (ly + ry) / 2;
            build_y(vx, lx, rx, vy*2, ly, my);
            build_y(vx, lx, rx, vy*2+1, my+1, ry);
            t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
        }
    }

    void build_x()

    void build(vector<vector<int>>& matrix) {
        build_x(1, 0, n-1);
    }
};

int main() {
    SegTree2D segTree;
    // initialize 'segTree.a' and 'segTree.n', 'segTree.m'
    // ...

    segTree.build();

    return 0;
}
