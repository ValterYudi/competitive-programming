#include <bits/stdc++.h>


 
using namespace std;
 
typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;
 
#define mp make_pair
#define F first
#define S second

int n;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs(int x1, int y1, int x2, int y2){
	queue<ii> q;
	q.push(mp(x1, y1));
	vector<vb> visited(n, vb(n, false));
	visited[x1][y1] = true;
	int dist = 0;
	while(!q.empty()){
		int sz = q.size();
		while(sz--){
			ii u = q.front(); q.pop();
			if(u.F == x2 && u.S == y2) return dist;
			for(int i = 0; i < 8; ++i){
				int x = u.F + dx[i];
				int y = u.S + dy[i];
				if(valid(x, y) && !visited[x][y]){
					visited[x][y] = true;
					q.push(mp(x, y));
				}
			}
		}
		dist++;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--){
		cin >> n;
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << bfs(x1, y1, x2, y2) << endl;
	}
	return 0;
}
