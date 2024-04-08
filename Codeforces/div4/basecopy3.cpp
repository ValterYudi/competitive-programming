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
        int  n, k; cin >> n >> k;
        vi v(n);
        for(auto &a: v) cin >> a;
        sort(v.begin(), v.end());
        int ls= 1, as = 1;
        int ant = v[0];
        for(int i = 1; i < n; i++){
            if(v[i] - ant <= k){
                as++;
            }else{
                ls = max(ls, as);
                as = 1;
            }
            ant = v[i];
        }
        ls = max(ls, as);
        cout << n -ls << endl;

    }
}