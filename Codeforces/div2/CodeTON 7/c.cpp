#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
// 1 2 3 4 5
// 1 2 2 3 4
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector<ii> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }

        vi b(n);
        for(int i = 0; i < n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int count = 0;
        for(int i = 0; i < n; i++){
            if(a[i].first > b[(i+x)%n]){
                count++;
            }
        }
        
        for(int i = 0; i < n; i++){
            a[i].first = a[i].second;
            a[i].second = b[(i+x)%n];
        }
        sort(a.begin(), a.end());
        if(count != x){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                cout << a[i].second << " ";
            }
            cout << endl;
        }
    }
    return 0;
}