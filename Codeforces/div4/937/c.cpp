#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void solve(){
    string s, ts = "AM"; cin >> s;

    int hora = stoi(s.substr(0, 2));
    int minuto = stoi(s.substr(3, 2));
    if(hora > 12){
        hora -= 12;
        ts = "PM";
    }else if(hora == 12){
        ts = "PM";
    }else if(hora == 0){
        hora = 12;
    }
    if(hora < 10){
        cout << "0";
    }
    cout << hora << ":";
    if(minuto < 10){
        cout << "0";
    }
    cout << minuto << " " << ts << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
