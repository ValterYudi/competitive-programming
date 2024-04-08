#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

̣//DSU
struct DSU{
    vi p, r;
    DSU(int n){
        p.assign(n, 0);
        r.assign(n, 0);
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(r[x] > r[y]) p[y] = x;
            else{
                p[x] = y;
                if(r[x] == r[y]) r[y]++;
            }
        }
    }
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        string s; cin >> s;
        vi v;
        char ant = '*';
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == ant){
                int j = i;
                while(j < s.size() && s[j] == '1') j++;
                v.push_back(j - i);
                i = j;
            }
        }
        
    }
}