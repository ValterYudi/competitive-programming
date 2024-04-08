#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n; cin >> n;
    vi v(n);
    for(auto &a: v) cin >> a;
    int soma = 0, count_1 = 0, count_2 = 0;
    for(auto e : v){
        soma += abs(e);
        if(e%3 == 1) count_1++;
        else if(e%3==2) count_2++;
    }
    if(soma % 3){
        if(soma%3 == 2 or count_1){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }else{
        cout << 0 << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}