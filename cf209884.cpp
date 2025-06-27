#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n;
	cin >> n;
	int a[n][n];
	int dis[n][n] = {};
	bool vis[n][n][2] = {};
	queue<tuple<int, int, bool>> q;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}
	q.push({0, 0, 0});
	dis[0][0] = 1;
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	while (!q.empty()) {
		auto [x, y, z] = q.front();
		q.pop();
		if (x == n - 1 and y == n - 1) {
			cout << dis[x][y];
			return 0;
		}
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 or ny < 0 or nx >= n or ny >= n) continue;
			if ((x != 0 or y != 0) and (a[x][y] > a[nx][ny] == z)) continue;
			if (vis[nx][ny][a[x][y] > a[nx][ny]]) continue;
			q.push({nx, ny, a[x][y] > a[nx][ny]});
			vis[nx][ny][a[x][y] > a[nx][ny]] = 1;
			dis[nx][ny] = dis[x][y] + 1;
		}
	}
	cout << -1;
}

