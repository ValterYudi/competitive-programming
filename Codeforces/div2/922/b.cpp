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
        int n; cin >> n;
        vector<ii> soma, a_i;
        vi a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++){
            a_i.push_back({a[i], i});
        }
        sort(a_i.begin(), a_i.end());
        vi b_aux = b;
        for(int i = 0; i < n; i++){
            b[i] = b_aux[a_i[i].second];
        }
        for(int i = 0; i < n; i++){
            soma.push_back({(a_i[i].first + b[i]), i});
        }
        sort(soma.begin(), soma.end());
        for(int i = 0; i < n; i++){
            int pos = soma[i].second;
            cout << a_i[pos].first << " ";
        }
        cout << endl;
        
        for(int i = 0; i < n; i++){
            int pos = soma[i].second;
            cout << b[pos] << " ";
        }
        cout << endl;
    }
}
2 3 1 4 6 5 
1 2 6 4 3 5 
1 1 2 1 1 0

2 3 4 6 5 1
1 2 4 3 5 6
1 1 2 2 1 0