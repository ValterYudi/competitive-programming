#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

#define mp make_pair
#define F first
#define S second

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t, n, q; cin >> t;
	while(t--){
		cin >> n >> q;
		vector<vector<ll>> rect(2001, vector<ll>(2001, 0));
		for(int k = 0; k < n; k++){
			int h, w; cin >> h >> w;
			rect[h][w] += h*w;
		}
		

		ll soma = 0;
		for(int i = 1; i <=  1000; i++){
			for(int j = 1; j <= 1000; j++){
				soma = ((rect[i][j-1] + rect[i-1][j]) - rect[i-1][j-1]) + rect[i][j];
				rect[i][j] = soma;
			}
		}

		while(q--){
			int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
			ll ans = rect[hb-1][wb-1] - (rect[hb-1][ws] + rect[hs][wb-1] - rect[hs][ws]);
			cout << ans << endl;
		}
	}
  return 0;
}
