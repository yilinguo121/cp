#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (auto &x : s) cin >> x;
	queue<pair<int, int>> q;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	vector<vector<int>> cnt(h, vector<int> (w));
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			for (int k = 0;k < 4;k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (ni >= 0 and ni < h and nj >= 0 and nj < w and s[ni][nj] == '#') cnt[i][j]++;
			}
		}
	}
	bool vis[h][w];
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			vis[i][j] = 0;
			if (s[i][j] == '.' and cnt[i][j] == 1) {
				q.push({i, j});
				vis[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (auto x : s) {
		for (auto y : x) if (y == '#') ans++;
	}
	while (!q.empty()) {
		auto v = q;
		q = {};
		vector<pair<int, int>> p;
		while (!v.empty()) {
			auto [x, y] = v.front();
			v.pop();
			ans++;
			s[x][y] = '#';
			for (int i = 0;i < 4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 or nx >= h or ny < 0 or ny >= w) continue;
				if (s[nx][ny] == '#') continue;
				cnt[nx][ny]++;
				p.push_back({nx, ny});
			}
		}
		for (auto [nx, ny] : p) {
			if (s[nx][ny] == '.' and !vis[nx][ny] and cnt[nx][ny] == 1) {
				vis[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
	cout << ans;
}
