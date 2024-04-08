#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

ll sum_diagonal(vector<vector<ll>> &v, int i, int j){
    ll sum = 0;
    int l = i, r = j;
    while(l < v.size() && r < v[0].size()){
        sum += v[l][r];
        l++; r++;
    }
    l = i-1; r = j-1;
    while(l >= 0 && r >= 0){
        sum += v[l][r];
        l--; r--;
    }
    l = i+1; r = j-1;
    while(l < v.size() && r >= 0){
        sum += v[l][r];
        l++; r--;
    }
    l = i-1; r = j+1;
    while(l >= 0 && r < v[0].size()){
        sum += v[l][r];
        l--; r++;
    }
    return sum;
}

ll search_diagonals(vector<vector<ll>> &v, int n, int m){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum = max(sum, sum_diagonal(v, i, j));
        }
    }
    
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;
        vi candies(n), checked;
        map<int, int> count;
        for(auto &c : candies){
            cin >> c;
            count[c]++;
            if(count[c] > k){
                checked.push_back(c);
            }
        }
        sort(checked.begin(), checked.end());
        //get the positions i and j of the longest sequence of checked (incresing 1)
        int ant, l = 0, r =0, max = 1, l_save = 0, r_save = 0;
        for(int i = 0; i < checked.size(); i++){
            if(i == 0){
                ant = checked[i];
                l = i;
                r = i;
            }else{
                if(checked[i] == ant+1){
                    r = i;
                    if(r-l+1 >= max){
                        max = r-l+1;
                        l_save = l;
                        r_save = r;
                    }
                }else{
                    l = i;
                    r = i;
                }
                ant = checked[i];
            }
        }
        if(max == 0){
            cout << -1 << endl;
            continue;
        }else{
            cout << checked[l_save] << " " << checked[r_save] << endl;
        }
        
    }
    return 0;
}
