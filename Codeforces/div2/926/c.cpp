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
        int k, x, a; cin >> k >> x >> a;
        x++;
        if(k >= x){
            if(a > k){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
            continue;
        }
        //fator da soma de pa é k-1 e o primeiro termo é k-1
        //a soma de pa é (a1+an)*n/2 == (k-1 + (x)*(k-1))*n/2
        //1 1 1 2 2 2 3 3 3 4
        //1 2 3 4 5 6 7 8 9 10
        int aux = x/(k-1), dec = ((((aux+1)*aux)/2)*(k-1));
        cout << "x: " << x << " k: " << k << " a: " << a << " aux: " << aux;
        //1 2
        cout << " dec: " << dec << endl;
        dec += (aux+1)*(x%(k-1));
        cout << " dec: " << dec << endl;
        if(dec >= a){
            cout <<"NO\n";
        }else{
            cout << "YES\n";
        }
        
    }
}
