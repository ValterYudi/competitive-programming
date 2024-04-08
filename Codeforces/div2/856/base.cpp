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
        vi v(n), ans(n);
        stack<int> s;
        map<int, int> m;
        for(int i = 0; i < n; ++i) cin >> v[i];
        for(int i = 0; i < n; ++i){
            ans[i] = v[i] - i+1;
            if(ans[i] == 0) s.push(i);
            m[ans[i]]++;
        }
        while(!s.empty()){
            int i = s.top(); s.pop();
            if(m[ans[i]] > 1){
                ans[i] = n+1;
                m[ans[i]]++;
            }
        }
    }
}
