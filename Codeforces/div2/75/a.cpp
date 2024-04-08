#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        n = ((n+1)*n)/2;
        m %= n;
        int i = 1;
        while(m>0){
            m -= i;
            i++;
        }
        if(m == 0){
            cout << 0 << endl;
        }else{
            cout << m+i-1 << endl;
        }
        
    }
}
