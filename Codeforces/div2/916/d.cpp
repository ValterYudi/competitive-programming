#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vi v(n);
        bool check = false;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] <= 0){
                check ^= 1;
                mini = min(mini, abs(v[i]));
            }
        }
        if(check or mini == 0){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
            cout << 1 << " " << 0 << endl;
        }

    }
}
