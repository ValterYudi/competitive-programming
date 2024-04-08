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
        string a =  "", b = "";
        for(int i = 0; i < (2*n - 2); i++){
            string s; cin >> s;
            if(s.size() == n-1){
                if(a.size() == 0){
                    a = s;
                }
                else{
                    b = s;
                }
            }
        }
        reverse(b.begin(), b.end());
        if(a==b){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
// 1 2 4 8 16 32 64 128 256 512 1024 2048 4096
// 1 3 7 15 31 63 127 255 511 1023 2047 4095
// 3 xor 7 = 4