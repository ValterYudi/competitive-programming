#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

void checker(vi &v){
    int n = v.size()-1;
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

vi find_permutation(int n){
    vi v(n+1);
    set<int> s;
    for(int i = 1; i <= n; i++){
        i += i*(i+(n%2==0)+3);
        v[i] = i%n;
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vi v = find_permutation(n);
        for(int i = 1; i < n; i++){
            cout << v[i] << " ";
        }
        cout << v[n] << endl;
    }
}