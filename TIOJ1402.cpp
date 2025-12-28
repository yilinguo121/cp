#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	IO
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> v(n, vector<int>(m));
		vector<vector<bool>> vis(n, vector<bool>(m));
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				cin >> v[i][j];
			}
		}
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
		for (int i = 0;i < n;i++) {
			q.push({v[i][0], i, 0});
			vis[i][0] = 1;
			if (m == 1) continue;
			q.push({v[i][m - 1], i, m - 1});
			vis[i][m - 1] = 1;
		}
		for (int j = 0;j < m;j++) {
			q.push({v[0][j], 0, j});
			vis[0][j] = 1;
			if (n == 1) continue;
			q.push({v[n - 1][j], n - 1, j});
			vis[n - 1][j] = 1;
		}
		int dx[4] = {0, 0, 1, -1};
		int dy[4] = {1, -1, 0, 0};
		int ans = 0;
		while (!q.empty()) {
			auto [h, x, y] = q.top();
			q.pop();
			for (int i = 0;i < 4;i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
				if (vis[nx][ny]) continue;
				vis[nx][ny] = 1;
				if (v[nx][ny] < h) ans += h - v[nx][ny];
				q.push({max(h, v[nx][ny]), nx, ny});
			}
		}
		cout << ans << '\n';
	}
}

