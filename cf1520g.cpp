#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int n, m, w;
int a[2001][2001];
long long vis[2001][2001];
long long ans[2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void bfs(int sx, int sy, bool way) {
	ans[way] = 1e18;
	queue<pair<int, int>> q;
	memset(vis, -1, sizeof(vis));
	q.push({sx, sy});
	vis[sx][sy] = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (a[x][y] > 0) ans[way] = min(ans[way], vis[x][y] + a[x][y]);
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 or ny < 1 or nx > n or ny > m) continue;
			if (a[nx][ny] == -1 or vis[nx][ny] != -1) continue;
			q.push({nx, ny});
			vis[nx][ny] = vis[x][y] + w;
		}
	}
}
int main() {
	IO
	cin >> n >> m >> w;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			cin >> a[i][j];
		}
	}
	bfs(1, 1, 0);
	bfs(n, m, 1);
	long long t = ans[0] + ans[1];
	if (vis[1][1] != -1) t = min(t, vis[1][1]);
	if (t >= 1e18) cout << -1;
	else cout << t;
}
