#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

bool is_palindrome(vector<int> &v, int x){
    int n = v.size();
    for(int i = 0; i < (n+1)/2; i++){
        if(v[i]%x != v[n-i-1]%x) return false;
    }
    return true;
}
   


int busca_bin(vi &v, vi &restos){
    int l = 0, r = restos.size()-1;

    while(l < r){
        int mid = (l+r+1)/2;

        if(is_palindrome(v, restos[mid])){
            l = mid;
        }else{
            r = mid-1;
        }
    }
    if(is_palindrome(v, restos[l])) return restos[l];
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        //talvez fila de prioridade
        vi v(n), restos;
        for(auto &x : v) cin >> x;
        for(int i = 0; i < (n+1)/2; i++){
            if(v[i] == v[n-i-1]) continue;
            restos.push_back(abs(v[i] - v[n-i-1]));
        }
        if(restos.size() == 0){
            cout << 0 << endl;
            continue;
        }
        sort(restos.begin(), restos.end());
        int ans = busca_bin(v, restos);
        cout << ans << endl;
    }
}
