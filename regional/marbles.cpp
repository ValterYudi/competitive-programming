#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_L = 105;
const int MAX_C = 105;

int grundy[MAX_L][MAX_C]; // Grundy numbers

int calculateGrundy(int l, int c) {
    if (l == 0 && c == 0) return 0; // Base case: winning position
    if (grundy[l][c] != -1) return grundy[l][c]; // Memoization

    unordered_set<int> mex; // Set to calculate the minimum excludant

    for (int u = 1; l - u >= 0; u++)
        mex.insert(calculateGrundy(l - u, c));
    
    for (int u = 1; c - u >= 0; u++)
        mex.insert(calculateGrundy(l, c - u));

    for (int u = 1; l - u >= 0 && c - u >= 0; u++)
        mex.insert(calculateGrundy(l - u, c - u));
    
    int g = 0;
    while (mex.count(g)) g++; // Calculate Grundy number

    cout << "Grundy[" << l << "][" << c << "] = " << g << endl;
    return grundy[l][c] = g;
}

int32_t main() {
    int n;
    cin >> n;

    memset(grundy, -1, sizeof(grundy)); // Initialize the array

    while (n--) {
        int l, c;
        cin >> l >> c;
        calculateGrundy(l, c);
    }

    int xor_sum = 0;
    for (int i = 0; i < MAX_L; i++) {
        for (int j = 0; j < MAX_C; j++) {
            if (grundy[i][j] == -1)
                xor_sum ^= calculateGrundy(i, j);
        }
    }

    if (xor_sum != 0)
        cout << "Y\n"; // The Emperor can win
    else
        cout << "N\n"; // The Emperor cannot win

    return 0;
}