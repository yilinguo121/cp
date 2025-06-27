#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, m;
	cin >> n >> m;
	char c[n][m];
	bool vis[n][m] = {};
	for (int i = 0;i < n;i++) for (int j = 0;j < m;j++) cin >> c[i][j];
	int ans = 0;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (c[i][j] == '.' and !vis[i][j]) {
				ans++;
				queue<pair<int, int>> q;
				q.push({i, j});
				while (!q.empty()) {
					auto [x, y] = q.front();
					q.pop();
					for (int k = 0;k < 4;k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
						if (vis[nx][ny] or c[nx][ny] != '.') continue;
						q.push({nx, ny});
						vis[nx][ny] = 1;
					}
				}
			}
		}
	}
	cout << ans;
}

