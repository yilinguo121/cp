#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n, m;
	cin >> n >> m;
	char a[n][m];
	bool vis[n][m] = {}, vis_m[n][m] = {};
	pair<int, int> pa[n][m], start;
	queue<pair<int, int>> q, p;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> a[i][j];
			if (a[i][j] == 'A') {
				q.push({i, j});
				start = {i, j};
			}
			if (a[i][j] == 'M') p.push({i, j});
		}
	}
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			auto [x, y] = q.front();
			q.pop();
			if (a[x][y] == 'M') continue;
			if (x == 0 or x == n - 1 or y == 0 or y == m - 1) {
				cout << "YES\n";
				vector<char> ans;
				pair<int, int> now = {x, y};
				while (now != start) {
					auto t = pa[now.first][now.second];
					if (now.first > t.first) ans.push_back('D');
					if (now.first < t.first) ans.push_back('U');
					if (now.second > t.second) ans.push_back('R');
					if (now.second < t.second) ans.push_back('L');
					now = t;
				}
				reverse(ans.begin(), ans.end());
				cout << ans.size() << '\n';
				for (auto x : ans) cout << x;
				return 0;
			}
			for (int i = 0;i < 4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
				if (vis[nx][ny] or a[nx][ny] != '.') continue;
				q.push({nx, ny});
				vis[nx][ny] = 1;
				pa[nx][ny] = {x, y};
			}
		}
		sz = p.size();
		while (sz--) {
			auto [i, j] = p.front();
			p.pop();
			for (int k = 0;k < 4;k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (ni < 0 or nj < 0 or ni >= n or nj >= m) continue;
				if (a[ni][nj] != '.' or vis_m[ni][nj]) continue;
				a[ni][nj] = 'M';
				p.push({ni, nj});
				vis_m[ni][nj] = 1;
			}
		}
	}
	cout << "NO";
}
