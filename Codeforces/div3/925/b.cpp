#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n; cin >> n;
    vi a(n);
    int soma = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        soma += a[i];
    }
    int media = soma/n, rem = 0;
    for(auto x: a){
        if(x > media)
            rem += x-media;
        else
            rem -= media-x;
        if(rem < 0){
            cout << "NO\n";
            return;
        }
    }
    if(rem == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}