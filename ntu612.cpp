#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
pair<int, int> now;
int n, m, a[55][55];
bool vis[55][55];
map<pair<int, int>, pair<int, int>> p;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool check(int x, int y) {
	if (x < 0 or x >= n or y < 0 or y >= m) return 0;
	if (a[x][y] == 1 or vis[x][y]) return 0;
	return 1;
}
void dfs(int x, int y) {
	vis[x][y] = 1;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!check(nx, ny)) continue;
		p[{nx, ny}] = pair<int, int>{x, y};
		if (a[nx][ny] == 3) {
			vector<pair<int, int>> ans;
			while (nx != -1 and ny != -1) {
				ans.push_back({nx, ny});
				pair<int, int> next = p[{nx, ny}];
				nx = next.first;
				ny = next.second;
			}
			reverse(ans.begin(), ans.end());
			cout << ans.size() << '\n';
			for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
			exit(0);
		}
		dfs(nx, ny);
	}
}
int main() {
	IO
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) now = pair<int, int>{i, j};
		}
	}
	p[{now.first, now.second}] = pair<int, int>{-1, -1};
	dfs(now.first, now.second);
	cout << 0;
}
