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
        string s;
        if(n > 52){
            s += char(n-53+'a');
            s += "zz";
        }else if(n > 27){
            s += 'a';
            n -= 28;
            s += char(n+'a');
            s += 'z';
        }else{
            s += "aa";
            s += char(n-3+'a');
        }
        cout << s << endl;
    }
}
