#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
//https://codeforces.com/contest/1722/problem/F
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;

    while(t--){
        int l, c, corners = 0; cin >> l >> c;
        vector<string> grid(l);
        vector<vector<int>> count(l, vector<int>(c, 0));
        for(int i = 0; i < l; i++){
            cin >> grid[i];
        }
        double count_tres = 0, count_dois = 0;
        bool check = true;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < c; j++){
                count[i][j] = (grid[i][j] == '*') ? 1 : 0;
                string dirs = "";
                corners = 0;
                if(i == 0 and i < l -1){
                    count[i][j] += (grid[i+1][j] == '*') ? 1 : 0;
                    dirs = "u";
                }else if (i == l - 1 and i > 0){
                    count[i][j] += (grid[i-1][j] == '*') ? 1 : 0;
                    dirs = "d";
                }else if (i > 0 and i < l - 1){
                    if(grid[i-1][j] == '*' and grid[i+1][j] == '*' and grid[i][j] == '*') count[i][j] = -100;
                    else{
                        count[i][j] += (grid[i-1][j] == '*') ? 1 : 0;
                        count[i][j] += (grid[i+1][j] == '*') ? 1 : 0;
                        dirs = "ud";
                    }
                }
                if(j == 0 and j < c -1){
                    count[i][j] += (grid[i][j+1] == '*') ? 1 : 0;
                    dirs += 'r';
                    if((dirs == "ud" or dirs == "u") and grid[i+1][j+1] == '*') corners++;
                    if((dirs == "ud" or dirs == "d") and grid[i-1][j+1] == '*') corners++;
                }else if (j == c - 1 and j > 0){
                    count[i][j] += (grid[i][j-1] == '*') ? 1 : 0;
                    if((dirs == "ud" or dirs == "u") and grid[i+1][j-1] == '*') corners++;
                    if((dirs == "ud" or dirs == "d") and grid[i-1][j-1] == '*') corners++;
                }else if (j > 0 and j < c - 1){
                    if(grid[i][j-1] == '*' and grid[i][j+1] == '*' and grid[i][j] == '*') count[i][j] = -100;
                    else{
                        count[i][j] += (grid[i][j-1] == '*') ? 1 : 0;
                        count[i][j] += (grid[i][j+1] == '*') ? 1 : 0;
                        if((dirs == "ud" or dirs == "u") and (grid[i+1][j-1] == '*' or grid[i+1][j+1] == '*')) corners += (grid[i+1][j-1] == '*' and grid[i+1][j+1] == '*') ? 2 : 1;
                        if((dirs == "ud" or dirs == "d") and (grid[i-1][j-1] == '*' or grid[i-1][j+1] == '*')) corners += (grid[i-1][j-1] == '*' and grid[i-1][j+1] == '*') ? 2 : 1;
                    }    
                }

                if(count[i][j] < 0 or corners > 1){
                    check = false;
                    cout << "count[i][j]: " << count[i][j] << " corners: " << corners << endl;
                    break;
                }else if(count[i][j] == 3){
                    count_tres++;
                }else if(count[i][j] == 2){
                    count_dois++;
                    if(corners != 1){
                        check = false;
                        cout << "TINHA MAIS DE UM CORNER" << endl;
                        break;
                    }
                }
            }
            if(!check) break;
        }
        cout << count_tres << " " << count_dois << " " << check << endl;
        if(!check or (count_tres != count_dois/2.0)){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}