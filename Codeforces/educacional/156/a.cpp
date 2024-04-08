#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
bool is_power_of_three(int n){
    if(n == 0) return false;
    while(n != 1){
        if(n % 3 != 0) return false;
        n /= 3;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a, b, c;
        a = 1;
        b = 2;
        c = n - 3;
        if(c % 3 == 0){
            c-=2;
            b+=2;
        }

        //cout << a << " " << b << " " << c << "\n";
        if(a % 3 == 0 || b % 3 == 0 || c % 3 == 0 || c == a || b == c || c < 0) cout << "NO\n";
        else cout << "YES\n" << a << " " << b << " " << c << "\n";

    }
}