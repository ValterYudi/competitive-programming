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
        int count = 2, ans = 0;
        map<char, int> mp;
        mp[s[0]] = 1;
        set<char> st;
        st.insert(s[0]);
        for(int i =1; i < n; i++){
            if(mp.count(s[i]) == 0){
                mp[s[i]] = i + 1;
                count++;
                ans += count;
                //cout << "count: " << count << endl;
            }else{
                count = i - mp[s[i]] + 1;
                mp[s[i]]++;
                ans += count;
            }
        }
        cout << ans << endl;
    }
}
