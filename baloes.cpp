#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b, flechas = 0; cin >> n;
    map<int, int> balao;
    for(int i = 0; i < n ; i++){
        cin >> b;
        if(balao.count(b+1) == 0){
            flechas++;
	    cout << balao.count(b+1) << endl;
        }else{
            balao[b+1]--;
	    cout <<balao.count(b+1)<< " tinha flecha vindo!!" << endl;
        }
        balao[b]++;
    }
    cout << flechas << endl;

}
