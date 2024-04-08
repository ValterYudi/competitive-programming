#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;



int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s; cin >> s;
        bool check_bb = false, existe_b = false;
        if(s[s.size()-1] == 'B' or s[0] == 'B'){
            check_bb = true;
        }else{
            for(int i = 0; i < s.size() - 1; i++){
                if(s[i] == 'B' and s[i+1] == 'B'){
                    check_bb = true;
                }
                existe_b = existe_b or (s[i] == 'B');
            }
        }
        if(check_bb){
            ll count = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == 'A'){
                    count++;
                }
            }
            cout << count << endl;
        }else if(existe_b){
            ll count = 0, count_a = 0, menor = s.size();
            for(int i = 0; i < s.size(); i++){
                if(s[i] == 'A'){
                    count_a++;
                    count++;
                }else if(count > 0){
                    menor = min(menor, count);
                    count = 0;
                }
            }
            if(count > 0) menor = min(menor, count);
            count_a -= menor;
            cout << count_a << endl;
        }else{
            cout << 0 << endl;
        }
    }
    
    return 0;
}
