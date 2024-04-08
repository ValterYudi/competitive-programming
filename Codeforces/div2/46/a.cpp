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
        string s, aux;
        while(cin >> aux){
            s += aux;
        }
        int n = s.size();
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
        //cout << s[n-1] << endl;
        if(vowels.count(s[n-2])){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
