#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;



const ll MOD = 998244353;

ll factorial(ll n) {
    return (n == 0 || n == 1) ? 1 : (n * factorial(n - 1)) % MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size(), aux = 0;
        vi cont;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) aux++;
            else {
                if(aux > 0) cont.push_back(aux + 1);
                aux = 0;
            }
        }
        if (aux > 0) cont.push_back(aux + 1);

        ll removes = 0;
        ll possibilities = 1;

        for (int i = 0; i < cont.size(); i++) {
            removes += cont[i] - 1;
            possibilities = (possibilities * (cont[i])) % MOD;
        }
        if(cont.size()) possibilities = (possibilities *factorial(removes)) % MOD;

        cout << removes << " " << possibilities << "\n";
    }
    return 0;
}