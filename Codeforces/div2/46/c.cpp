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
        int n; cin >> n;
        if(n % 2){
            int aux = 1;
            cout << "1 ";
            for(int i = 2; i <= n; i++){
                cout << i+aux << " ";
                aux *= (-1);
            }
            cout << '\n';
        }else{
            int aux = 1;
            cout << n << " ";
            for(int i = 2; i < n; i++){
                cout << i+aux << " ";
                aux *= (-1);
            }
            cout << "1\n";
        }
    }
}
