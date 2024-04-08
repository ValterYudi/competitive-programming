#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t; cin >> t;
    while(t--){
        string a, b, aux_a, aux_b; cin >> a >> b;
        set<string> s_a, s_b;
        if(a == b){
            cout << "YES\n";
            continue;
        }
        s_a.insert(a); s_b.insert(b);
        aux_a = a; aux_b = b;
        int l = -1, rv = -1;
        for(int i=0; i<a.size(); i++){
            if(a[i] == '0'){
                l = i;
                rv = a.size() - 1;
                while(i < rv and a[rv] == '1'){
                    rv--;
                }
                break;
            }
        }
        //cout << "l: " << l << " rv: " << rv << "\n";
        for(int i=l; i>=0 and i<=rv; i++){
            aux_a[i] = '0';
        }
        //cout << "Depois de mudar o a: " << aux_a << "\n";
        s_a.insert(aux_a);
        aux_a = a;
        l = rv = -1;
        for(int i=0; i<b.size(); i++){
            if(b[i] == '0'){
                l = i;
                rv = b.size() - 1;
                while(i < rv and b[rv] == '1'){
                    rv--;
                }
                break;
            }
        }
        //cout << "l: " << l << " rv: " << rv << "\n";
        for(int i=l; i>=0 and i<=rv; i++){
            aux_b[i] = '0';
        }
        // << "Depois de mudar o b(0): " << aux_b << "\n";
        s_b.insert(aux_b);
        aux_b = b;
        l = rv = -1;
        for(int i=0; i<b.size(); i++){
            if(b[i] == '1'){
                l = i;
                rv = b.size() - 1;
                while(i < rv and b[rv] == '0'){
                    rv--;
                }
                break;
            }
        }
        //cout << "l: " << l << " rv: " << rv << "\n";
        for(int i=l; i>=0 and i<=rv; i++){
            aux_b[i] = '1';
        }
        //cout << "Depois de mudar o b(1): " << aux_b << "\n";
        s_b.insert(aux_b);
        l = rv = -1;
        for(int i=0; i<a.size(); i++){
            if(a[i] == '1'){
                l = i;
                rv = a.size() - 1;
                while(i < rv and a[rv] == '0'){
                    rv--;
                }
                break;
            }
        }
        //cout << "l: " << l << " rv: " << rv << "\n";
        for(int i=l; i>=0 and i<=rv; i++){
            aux_a[i] = '1';
        }
        //cout << "Depois de mudar o a(1): " << aux_a << "\n";
        s_a.insert(aux_a);
        bool check = true;
        for(auto a: s_a){
            //cout << a << " ";
            if(s_b.count(a)){
                cout << "YES\n";
                check = false;
                break;

            }
        }
        if(check) cout << "NO\n";
    }
}