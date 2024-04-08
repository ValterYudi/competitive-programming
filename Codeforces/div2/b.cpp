#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi v(n), aux(n);
        for(auto &a : v) cin >> a;
        //search for ai that ai+1 is divible by ai
        for(int i = 0; i < n-1; i++){
            if(v[i+1] % v[i] == 0){
                    aux[i]++;
                    aux[i+1]++;
            }
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(make_pair(aux[i], i));
        }
        sort(ans.begin(), ans.end());
        //add 1 to the elements in i and see if it is divisible by the next element
        int cont = 2*n;
        for(int i = 0; i < n; i++){
            int j = ans[i].second;
            if(aux[j] > 0){    
                v[j]++;
                cont--;
                if(j > 0){
                    while(v[j] % v[j-1] == 0 and cont> 0){
                        v[j]++;
                        cont--;
                    }
                }
                if(j < n-1){
                    while(v[j+1] % v[j] == 0 and cont> 0){
                        v[j]++;
                        cont--;
                    }
                }
            }
            if(cont <= 0) break;
        }
        for(auto a : v) cout << a << " ";
        cout << endl;
    }
}