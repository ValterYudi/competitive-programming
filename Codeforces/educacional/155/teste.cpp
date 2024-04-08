#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    vector<int> v = {0, 2, 4, 6, 12, 14};
    int n; cin >> n;
    auto it = lower_bound(v.begin(), v.end(), n);
    int pos = lower_bound(v.begin(), v.end(), n) - v.begin();
    if(it == v.end()) cout << "not found" << endl;
    else cout << "found" << endl;
    cout << v[pos] << endl;
}