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
            string s; cin >> s;
            char ant = s[0];
            int ans = 0;
            for(int i = 1; i < n; i++){
                if(s[i] == ant){
                    ans++;
                    ant = ant == '0' ? '1' : '0';
                }else{
                    ant = s[i];
                }
            }
            int ans2 = 1;
            ant = s[0] == '0' ? '1' : '0';
            for(int i = 1; i < n; i++){
                if(s[i] == ant){
                    ans2++;
                    ant = ant == '0' ? '1' : '0';
                }else{
                    ant = s[i];
                }
            }
            cout << min(ans, ans2) << endl;
            
        }
    }
