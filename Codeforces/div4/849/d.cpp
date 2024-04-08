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
        string s; cin  >> s;
        map<char, int> freq;
        set<char> freq_a;
        for(auto c: s){
            
            freq[c]++;
        }
        int cnta = 0, cntb = freq.size(), ans = 0;
        for(int i = n - 1; i >=0 ; i--){
            freq[s[i]]--;
            if(freq[s[i]] == 0) cntb--;
            if(!freq_a.count(s[i])){
                cnta++;
                freq_a.insert(s[i]);
            }
            ans = max(ans, cntb + cnta);
        }
        cout << ans << endl;

    }
}