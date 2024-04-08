#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 80000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int gcd_table[MAX_N][MAX_N];
    // Fill the gcd_table array with precomputed gcd values
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = i + 1; j < MAX_N; ++j) {
            cout<< i << " " << j << endl;
            gcd_table[i][j] = gcd_table[j][i] = __gcd(i, j);
        }
    }

    // Output the precomputed gcd values array
    cout << "{";
    for (int i = 0; i < MAX_N; ++i) {
        cout << "{";
        for (int j = 0; j < MAX_N; ++j) {
            cout << gcd_table[i][j];
            if (j < MAX_N - 1) {
                cout << ", ";
            }
        }
        cout << "}";
        if (i < MAX_N - 1) {
            cout << ",";
        }
        cout << endl;
    }
    cout << "}";

    return 0;
}
