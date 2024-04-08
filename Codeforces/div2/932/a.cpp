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
        string s; cin >> s;
        if(s[0] < s[s.size()-1] ){
            cout << s << endl;
        }else if(s[0] > s[s.size()-1]){
            string ans = s;
            reverse(s.begin(), s.end());
            ans = s + ans;
            cout << ans << endl;
        }else{
            int l = 0, r = s.size()-1;
            while(l < r && s[l] == s[r]){
                l++;
                r--;
            }
            if(l > r){
                cout << s << endl;
            }else if(s[l] < s[r] or (l == r and s[l] == s[r])){
                cout << s << endl;
            }else{
                string ans = s;
                reverse(s.begin(), s.end());
                ans = s + ans;
                cout << ans << endl;
            }
        }
    }
}
