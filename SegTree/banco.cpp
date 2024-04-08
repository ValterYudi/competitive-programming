#include <bits/stdc++.h>
#define MINN -1000000
using namespace std;

struct Node {
    int sum;
    int prefixSum;
    int suffixSum;
    int maxSum;
    int length;
};

class SegmentTree {
private:
    int size;
    vector<Node> tree;

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n);
    }

    void build(vector<int>& accounts, int node, int start, int end) {
        if (start == end) {
            tree[node].sum = tree[node].prefixSum = tree[node].suffixSum = tree[node].maxSum = accounts[start];
            tree[node].length = 1;
        } else {
            int mid = (start + end) / 2;
            build(accounts, 2 * node, start, mid);
            build(accounts, 2 * node + 1, mid + 1, end);
            mergeNodes(node, mid, end);
        }
    }

    void mergeNodes(int node, int mid, int end) {
        tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
        tree[node].prefixSum = max(tree[2 * node].prefixSum, tree[2 * node].sum + tree[2 * node + 1].prefixSum);
        tree[node].suffixSum = max(tree[2 * node + 1].suffixSum, tree[2 * node + 1].sum + tree[2 * node].suffixSum);
        tree[node].maxSum = max({ tree[node].sum, tree[2 * node].maxSum, tree[2 * node + 1].maxSum, tree[2 * node].suffixSum + tree[2 * node + 1].prefixSum });
        // Atualiza o tamanho da subsequência com a maior soma
        if(mid == 1 or end == 1)
            tree[node].length = max({
                tree[2 * node].length, 
                tree[2 * node + 1].length, 
                tree[2 * node].suffixSum >= 0 ? tree[2 * node + 1].length + 1: 0, 
                tree[2 * node + 1].prefixSum >= 0 ? tree[2 * node].length + 1 : 0, 
                tree[2 * node].suffixSum >= 0 && tree[2 * node + 1].prefixSum >= 0 ? tree[2 * node].length + tree[2 * node + 1].length : 0
                });
        tree[node].length = max({ 
            tree[2 * node].length, 
            tree[2 * node + 1].length, 
            tree[2 * node].suffixSum >= 0 ? 
            tree[2 * node + 1].length + 1: 0, 
            tree[2 * node + 1].prefixSum >= 0 ? tree[2 * node].length + 1 : 0, 
            tree[2 * node].suffixSum >= 0 && tree[2 * node + 1].prefixSum >= 0 ? tree[2 * node].length + tree[2 * node + 1].length : 0
            }); 
    }

    Node query(int node, int start, int end, int left, int right) {
        if (start > right || end < left) {
            // Interval outside the query range, return a neutral node
            return { MINN, MINN, MINN, MINN, 0 };
        }
        if (start >= left && end <= right) {
            // Interval completely inside the query range, return the node
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node leftResult = query(2 * node, start, mid, left, right);
        Node rightResult = query(2 * node + 1, mid + 1, end, left, right);
        Node mergedResult;
        mergedResult.sum = leftResult.sum + rightResult.sum;
        mergedResult.prefixSum = max(leftResult.prefixSum, leftResult.sum + rightResult.prefixSum);
        mergedResult.suffixSum = max(rightResult.suffixSum, rightResult.sum + leftResult.suffixSum);
        mergedResult.maxSum = max({ mergedResult.sum, leftResult.maxSum, rightResult.maxSum, leftResult.suffixSum + rightResult.prefixSum });
        // Atualiza o tamanho da subsequência com a maior soma
        mergedResult.length = max({ leftResult.length, rightResult.length, leftResult.suffixSum >= 0 ? rightResult.length + 1: 0, rightResult.prefixSum >= 0 ? leftResult.length + 1 : 0, leftResult.suffixSum >= 0 && rightResult.prefixSum >= 0 ? leftResult.length + rightResult.length : 0 }); 
        cout << "Node: " << node << " | start: " << start << " | end: " << end << " | left: " << left << " | right: " << right << " | sum: " << mergedResult.sum << " | prefixSum: " << mergedResult.prefixSum << " | suffixSum: " << mergedResult.suffixSum << " | maxSum: " << mergedResult.maxSum << " | length: " << mergedResult.length << endl;
        return mergedResult;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> accounts(n);
        for (int i = 0; i < n; i++) {
            cin >> accounts[i];
        }

        SegmentTree segTree(n);
        segTree.build(accounts, 1, 0, n - 1);

        int q;
        cin >> q;

        while (q--) {
            int start, end;
            cin >> start >> end;

            Node result = segTree.query(1, 0, n - 1, start - 1, end - 1);
            
            cout << result.maxSum << " " << result.length << endl;
        }
    }

    return 0;
}
