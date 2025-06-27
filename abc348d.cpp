#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int h, w;
	cin >> h >> w;
	char c[h + 1][w + 1];
	int m[h + 1][w + 1] = {};
	int vis[h + 1][w + 1];
	queue<array<int, 3>> q;
	int sx, sy;
	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			vis[i][j] = -1;
			cin >> c[i][j];
			if (c[i][j] == 'S') {
				sx = i, sy = j;
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int x, y, e;
		cin >> x >> y >> e;
		m[x][y] += e;
	}
	q.push({sx, sy, m[sx][sy]});
	vis[sx][sy] = m[sx][sy];
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	while (!q.empty()) {
		auto [x, y, e] = q.front();
		q.pop();
		if (!e or e < vis[x][y]) continue;
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 or ny < 1 or nx > h or ny > w) continue;
			if (c[nx][ny] == 'T') {
				cout << "Yes";
				return 0;
			}
			if (c[nx][ny] != '.') continue;
			if (max(m[nx][ny], e - 1) <= vis[nx][ny]) continue;
			vis[nx][ny] = max(m[nx][ny], e - 1);
			q.push({nx, ny, max(m[nx][ny], e - 1)});
		}
	}
	cout << "No";
}
