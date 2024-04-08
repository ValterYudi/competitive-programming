#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int solve(const vector<int> &v, int n, vector<vi> &gcd_matrix, int calculated){
    int total_sum = 0;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            total_sum += gcd_matrix[i][j] * (n - j - 1);
        }
    }

    return total_sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int calculated = 0;
    vector<vi> gcd_matrix;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = calculated; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                gcd_matrix[i][j] = gcd_matrix[j][i] = __gcd(v[i], v[j]);
            }
        }
        calculated = max(n, calculated);
        for(int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        int ans = solve(v, n, gcd_matrix, calculated);
        cout << ans << endl;
    }
}
