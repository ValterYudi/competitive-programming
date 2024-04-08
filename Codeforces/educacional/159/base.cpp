#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long          ll;
typedef long double        ld;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;
 
#define mp make_pair
#define F first
#define S second
// You are given an integer array a1,a2,…,an, all its elements are distinct.

// First, you are asked to insert one more integer an+1 into this array. an+1 should not be equal to any of a1,a2,…,an.

// Then, you will have to make all elements of the array equal. At the start, you choose a positive integer x (x>0). In one operation, you add x to exactly one element of the array. Note that x is the same for all operations.

// What's the smallest number of operations it can take you to make all elements equal, after you choose an+1 and x?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases.

// The first line of each testcase contains a single integer n (1≤n≤2⋅105).

// The second line contains n integers a1,a2,…,an (−109≤ai≤109). All ai are distinct.

// The sum of n over all testcases doesn't exceed 2⋅105.

// Output
// For each testcase, print a single integer — the smallest number of operations it can take you to make all elements equal, after you choose integers an+1 and x.

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--){
		ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 1; i < n; ++i) ans += a[i] - a[0];
        ll res = ans;
        for(int i = 1; i < n; ++i){
            ans -= (a[i] - a[i-1]) * (n - i);
            ans += (a[i] - a[i-1]) * i;
            res = min(res, ans);
        }
        cout << res << endl;
    }
	return 0;
}
