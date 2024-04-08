#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n; cin >> n;
    array<queue<int>, 3> rests;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        rests[x % 3].push(x);
    }
    int ans = 0;
    while(!rests[1].empty()){
        if(!rests[2].empty()){
            ans++;
            rests[1].pop();
            rests[2].pop();
        }else{
            break;
        }
    }
    ans += rests[0].size()/2;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    //int t = 1;  cin >> t; while(t--)
    solve1();
    
    return 0;
}