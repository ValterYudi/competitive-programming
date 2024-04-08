#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;

#define make_pair mp
#define F first
#define S second


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int p, soma = 0; cin >> p;
        priority_queue<ii> pq;
        for(int i = 0; i < s.size(); i++){
            int saux = int(s[i]-'a')+1;
            soma += saux;
            ii aux = {saux, i};
            pq.push(aux);
        }
        while(!pq.empty() and soma > p){
            ii aux = pq.top(); pq.pop();
            soma -= aux.F;
            s[aux.S] = '*';
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*') cout << s[i];
        }
        cout << endl;
    }
}