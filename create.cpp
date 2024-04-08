#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	long long a, b; cin >> a >> b;
    vector<long long> v;
	if(a%b == 0){
		for(long long i = 1; i <= sqrt(a); i++){
			if(a%(i) == 0){
				v.push_back(i);
			}
		}
        for(int j = v.size()-1; j >= 0; j--){
			if((a/v[j])%b == 0)
            	v.push_back(a/v[j]);
        }
        int pos = upper_bound(v.begin(), v.end(), b) - v.begin() - 1;
        for(int i = pos; i < v.size(); i++){
            cout << v[i] << " ";
        }
	}

	cout << endl; 
	return 0;
}