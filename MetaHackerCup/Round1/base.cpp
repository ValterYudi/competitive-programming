#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
//get the vector that the sum of the elements is equal to 41 and the product is equal to p and the number of elements is the minimum possible
void dp(vector<vi> &ans, int div, ll p, vi aux, int maxi){
    if(maxi < 0) return;
    cout << div << " " << p << " " << maxi << endl;
    if(p == 1){
        if(ans.size() == 0){
            ans.push_back(aux);
        }
        else if(ans[0].size() > aux.size() + maxi){
            ans.clear();
            ans.push_back(aux);
        }
        else if(ans[0].size() == aux.size() + maxi){
            ans.push_back(aux);
        }
        return;
    }
    if(div <= 0) return;
    if(p%div == 0 and div <= maxi){
        aux.push_back(div);
        dp(ans, div, p/div, aux, maxi-div);
        aux.pop_back();
    }
    dp(ans, div-1, p, aux, maxi);
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    for(int iter = 1; iter <= t; iter++){
        ll p; cin >> p;
        
        vector<vi> ans;
        vi aux;
        if(p == 1){
            ans = {{1}};
        }else{
            dp(ans, min(ll(41),p) , p, aux, 41);
        }
        if(ans.size() == 0){
            cout << "Case #" << iter << ": " << -1 << endl;
            continue;
        }
        int soma = 0;
        for(auto a : ans[0]){
            soma += a;
        }
        if(soma < 41){
            while(soma < 41){
                ans[0].push_back(1);
                soma++;
            }
        }
        cout << "Case #" << iter << ": " << ans[0].size() << " ";
        sort(ans[0].begin(), ans[0].end());
        for(int i = 0; i < ans[0].size() - 1; i++){
            cout << ans[0][i] << " ";
        }
            cout << ans[0][ans[0].size() - 1] << endl;
    }
}