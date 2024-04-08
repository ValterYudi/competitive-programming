#include <bits/stdc++.h>

using namespace std;
bool checker(string colors){
    char ant = 'A';
    int count = 0;
    for(char i : colors){
        if(ant == i){
		count++;
	}
	ant = i;
    }
    if(count > 1){
        return false;
    }
    return true;
    
}
int main(){
    int t; cin >> t;
    while(t--){
	    int n, m; cin >> n >> m;
        string a, b, test; cin >> a >> b;
    	reverse(b.begin(), b.end());
        bool dale = false;
        test = a + b;
        if(checker(test)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
}

