#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;


void solve1(){
    ll n, m, k; cin >> n >> m >> k;
    vi a(n), d(m), f(k);
    int imb = -37, ant = -37, pos = 0, ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> d[i];
    for(int i = 0; i < k; i++) cin >> f[i];

    for(int i = 1; i < n; i++){
        if(a[i] - a[i-1] >= imb){
            ant = imb;
            imb = a[i] - a[i-1];
            pos = i;
        }
    }
    if(ant == imb) cout << imb << '\n';
    else{
        //check if there is some combiantion of values of d and f that is between a[pos] and a[pos-1]
        sort(d.begin(), d.end());
        sort(f.begin(), f.end());
        int ndd = (a[pos] + a[pos-1])/2;
        
        for(int i = 0; i < m; i++){
            if(d[i] >= ndd) break;
            auto it = lower_bound(f.begin(), f.end(), ndd-d[i]);
            if(it != f.end()){
                ans = max({(a[pos] - (d[i] + *it)), (d[i] + *it) - a[pos-1]});
                if(ans < imb){
                    if(ant == -37){
                        imb = ans;
                        break;
                    }else if(ans <= ant){
                        imb = ant;
                        break;
                    }else imb = min(ans, imb);
                }
            }
        }
        cout << imb << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int t = 1;  cin >> t; while(t--)
        solve1();
    
    return 0;
}