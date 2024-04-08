#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;



void solve1(){
    ll a, b, l, k = 0; cin >> a >> b >>l;
    int ma = 1, mb = 1, auxl = l;
    while(auxl%a == 0){
        ma++;
        auxl /= a;
    }
    int L = auxl;
    while(auxl%b == 0){
        mb++;
        auxl /= b;
    }
    k += (ma*mb);
    int auxa = ma, auxb = mb;
    ma = 1, mb = 1, auxl = l;
    while(auxl%b == 0){
        mb++;
        auxl /= b;
    }
    while(auxl%a == 0){
        ma++;
        auxl /= a;
    }
    // condicao de inclusao
    if(mb > auxb and a != b){
        k += (ma*(mb-auxb));
    }

    if(a != b){
        int diff_a  = abs(auxa - ma), diff_b = abs(auxb - mb);
        if(diff_a>diff_b){
            int count = min(auxa, ma);
            for(int i = min(auxa, ma); i < max(auxa, ma); i++){
                auxl = L;
                int mb_ = 1;
                while(auxl%b == 0){
                    mb_++;
                    auxl /= b;
                }
                if(mb_ > auxb and mb_ < mb){
                    k += count;
                }
                L /= a;
                count++;
            }
        }
    }
    cout << k << endl;
}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}