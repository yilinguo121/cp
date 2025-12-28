#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,inline,fast-math")
#pragma GCC target("avx2,bmi2,popcnt,lzcnt")
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
string s;
bool vis[9][9];
int ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y, int id) {
	if (x == 7 and y == 1) {
		if (id == 48) ans++;
		return;
	}
	if (vis[x + 1][y] and vis[x - 1][y] and !vis[x][y + 1] and !vis[x][y - 1]) return;
	if (vis[x][y + 1] and vis[x][y - 1] and !vis[x + 1][y] and !vis[x - 1][y]) return;
	vis[x][y] = 1;
	if (s[id] == '?') {
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!vis[nx][ny]) dfs(nx, ny, id + 1);
		}
	}
	if (s[id] == 'D' and !vis[x + dx[0]][y + dy[0]]) dfs(x + dx[0], y + dy[0], id + 1);
	if (s[id] == 'U' and !vis[x + dx[1]][y + dy[1]]) dfs(x + dx[1], y + dy[1], id + 1);
	if (s[id] == 'L' and !vis[x + dx[2]][y + dy[2]]) dfs(x + dx[2], y + dy[2], id + 1);
	if (s[id] == 'R' and !vis[x + dx[3]][y + dy[3]]) dfs(x + dx[3], y + dy[3], id + 1);
	vis[x][y] = 0;
}
int main() {
	IO
	cin >> s;
	for (int i = 0;i <= 8;i++) vis[i][0] = 1, vis[0][i] = 1, vis[8][i] = 1, vis[i][8] = 1;
	dfs(1, 1, 0);
	cout << ans;
}
