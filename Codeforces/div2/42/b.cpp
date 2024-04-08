#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    map<char, int> np, text;
    string heading; getline(cin, heading);
    string target; getline(cin, target);
    for(int i = 0; i < heading.size(); i++){
        if(heading[i] != ' ') np[heading[i]]++;
    }
    for(int i = 0; i < target.size(); i++){
        if(target[i] != ' ' and np.count(target[i])) np[target[i]]--;
        else if(target[i] != ' ' and !np.count(target[i])){
            cout << "NO" << endl;
            return;
        }
        if(np[target[i]] == 0) np.erase(target[i]);
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    //int t = 1;  cin >> t; while(t--)
    solve1();
    
    return 0;
}