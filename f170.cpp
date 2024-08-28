#include<bits/stdc++.h>
using namespace std;
int mp[1005][1005], n;
bool vis[1005][1005];
int ans = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check(int x, int y) {
	if (x < 0 or y < 0 or x >= n or y >= n) return 0;
	if (vis[x][y]) return 0;
	return 1;
}
void bfs(int sx, int sy) {
	queue<int>qx,qy;
	qx.push(sx);
	qy.push(sy);
	vis[sx][sy] = 1;
	while(!qx.empty()){
		int x = qx.front(), y = qy.front();
		qx.pop();
		ans++;
		qy.pop();
		for(int i=0;i<4;i++){
			if(check(x+dx[i],y+dy[i]) and abs(mp[x][y] - mp[x + dx[i]][y + dy[i]]) <= 2){
				vis[x+dx[i]][y+dy[i]] = true;
				qx.push(x+dx[i]);
				qy.push(y+dy[i]);
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> n >> x >> y;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> mp[i][j];
		}
	}
	bfs(x, y);
	cout << ans;
}
