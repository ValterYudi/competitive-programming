#include <bits/stdc++.h>

using namespace std;

class MergeSortTree {
private:
    vector<vector<int>> tree;
    vector<int> arr;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start]};
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            merge(tree[2 * node].begin(), tree[2 * node].end(),
                  tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                  back_inserter(tree[node]));
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = {val};
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node].resize(end - start + 1);
            merge(tree[2 * node].begin(), tree[2 * node].end(),
                  tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
                  tree[node].begin());
        }
    }

    int query(int node, int start, int end, int l, int r, int a, int b) {
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) {
            return upper_bound(tree[node].begin(), tree[node].end(), b) - lower_bound(tree[node].begin(), tree[node].end(), a);
        }
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r, a, b) + query(2 * node + 1, mid + 1, end, l, r, a, b);
    }

public:
    MergeSortTree(const vector<int>& input) {
        arr = input;
        int n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void updateElement(int idx, int val) {
        update(1, 0, arr.size() - 1, idx, val);
    }

    int rangeSumQuery(int a, int b) {
        return query(1, 0, arr.size() - 1, 0, arr.size() - 1, a, b);
    }
};

int main() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(auto &a : arr) cin >> a;
    MergeSortTree mst(arr);
    while(q--){
        char op; cin >> op;

        if(op =='!'){
            int k, x; cin >> k >> x;
            mst.updateElement(k - 1, x);
        } else {
            int a, b; cin >> a >> b;
            cout << mst.rangeSumQuery(a, b) << endl;
        }
    }
    
    return 0;
}
