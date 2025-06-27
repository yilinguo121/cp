#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a[n][m], ans = 0;
		bool vis[n][m] = {};
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) cin >> a[i][j];
		}
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				if (!vis[i][j] and a[i][j]) {
					int cnt = 0;
					queue<pair<int, int>> q;
					q.push({i, j});
					vis[i][j] = 1;
					while (!q.empty()) {
						auto [x, y] = q.front();
						q.pop();
						cnt += a[x][y];
						for (int k = 0;k < 4;k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
							if (vis[nx][ny] or !a[nx][ny]) continue;
							q.push({nx, ny});
							vis[nx][ny] = 1;
						}
					}
					ans = max(ans, cnt);
				}
			}
		}
		cout << ans << '\n';
	}
}

