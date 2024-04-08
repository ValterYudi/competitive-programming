#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << "0\n";
        return;
    }
    int l = 0, r = n-1, aux = a[0];
    while(l+1 < n and (a[l+1] == aux)) l++;
    aux = a[n-1];
    while(r-1 >= 0 and (a[r-1] == aux)) r--;
    if(a[0] == a[n-1]){
        if(l == n-1){
            cout << "0\n";
            return;
        }
        cout << r-l-1 << '\n';
    }else{
        if(n-l-1 >= (r)){
            cout << r << '\n';
        }else{
            cout << n-l-1 << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}