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
        int n, m; cin >> n >> m;
        string x, s; cin >> x >> s;
        bool flag = false;
        int count = 0;
        while(x.size() < 50){
            //check if s is a substring of x
            if(x.find(s) != string::npos){
                flag = true;
                break;
            }
            if(flag) break;
            x += x;
            count++;
        }
        if(flag) cout << count << endl;
        else cout << "-1\n";
    }
}