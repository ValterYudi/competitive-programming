#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n, m; cin >> n >> m;
    if(n == 1 and m == 2){
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << n << " " << m << endl;
        cout << 1 << " " << 1 << endl;
    }else if(n == 2 and m == 1){
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << n << " " << m << endl;
        cout << 1 << " " << 1 << endl;
    }else if(n%2 && m%2 or n == 1 or m == 1){
        cout << 1 << endl;
        cout << n << " " << m << " " << 1 << " " << 1 << endl;
        for(int i = 1; i <= n; i++){
            if(i%2){
                for(int j = 1; j <= m; j++){
                    cout << i << " " << j << endl;
                }
            }else{
                for(int j = m; j >= 1; j--){
                    cout << i << " " << j << endl;
                }
            }
        }
        cout << 1 << " " << 1 << endl;
    }else if(n%2){
        cout << 0 << endl;
        //faz o L
        for(int i = 1; i <= n; i++){
            cout << i << " " << 1 << endl;
        }
        for(int i = 2; i <= m; i++){
            cout << n << " " << i << endl;
        }
        for(int j = m; j >= 2; j--){
            if((m-j)%2){
                for(int i = 1; i <= n-1; i++){
                    cout << i << " " << j << endl;
                }
            }else{
                for(int i = n-1; i >= 1; i--){
                    cout << i << " " << j << endl;
                }
            }
        }
        cout << 1 << " " << 1 << endl;
    }else{
        cout << 0 << endl;
        //faz o L
        for(int i = 1; i <= n; i++){
            cout << i << " " << 1 << endl;
        }
        for(int i = 2; i <= m; i++){
            cout << n << " " << i << endl;
        }
        for(int j = n-1; j >= 1; j--){
            if((n-j)%2){
                for(int i = m; i >= 2; i--){
                    cout << j << " " << i << endl;
                }
            }else{
                for(int i = 2; i <= m; i++){
                    cout << j << " " << i << endl;
                }
            }
        }
        cout << 1 << " " << 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    //int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}