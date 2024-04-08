    #include<bits/stdc++.h>

    using namespace std;

    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<bool> vb;
    typedef pair<int, int> ii;

    #define lll __int128

    ll power(ll x){
        ll res = 1;
        while(x > 0){
            res *= 2;
            x--;
        }
        return res;
    }

    int main(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> v(n);
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == '.'){
                    grid[i][j] = 1;
                    if(i > 0){
                        grid[i][j] += grid[i-1][j];
                    }
                    if(j > 0){
                        grid[i][j] += grid[i][j-1];
                    }
                }
            }
            for(int j=m-2; j>=0; j--){
                if(v[i][j] == '.'){
                    grid[i][j] = max(grid[i][j], grid[i][j+1]);
                }
            }
        }
    }