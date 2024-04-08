#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    int n, k; cin >> n >> k;
    vi a(n); for(int i=0; i<n; i++) cin >> a[i];
    vi b(n); for(int i=0; i<n; i++) cin >> b[i];
    int maior = 0, soma = 0, ans = 0;
    for(int i=0; i<min(k, n); i++){
        soma += a[i];
        maior = max(maior, b[i]);
        soma += maior*(k-i-1);
        ans = max(ans, soma);
        soma -= maior*(k-i-1);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}