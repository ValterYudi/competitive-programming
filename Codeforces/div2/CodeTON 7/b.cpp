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
        string s; cin >> s;
        ll count = 0;
        for(int i = 0; i < n - 1; ++i){
            if(s[i] == 'A' and s[i+1] == 'B'){
                count++;
                swap(s[i], s[i+1]);
            }
        }
        for(int i = n-1; i > 0; --i){
            if(s[i] == 'B' and s[i-1] == 'A'){
                count++;
                swap(s[i], s[i-1]);
            }
        }
        cout << count << endl;
    }
}
