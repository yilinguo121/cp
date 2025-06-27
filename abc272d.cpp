#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, m;
	cin >> n >> m;
	int k = sqrt(m);
	vector<pair<int, int>> v;
	for (int i = -k - 1;i < k + 1;i++) {
		for (int j = -k - 1;j < k + 1;j++) {
			if (i * i + j * j == m) v.push_back({i, j});
		}
	}
	int dis[n][n] = {};
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++) dis[i][j] = -1;
	queue<pair<int, int>> q;
	q.push({0, 0});
	dis[0][0] = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (auto [dx, dy] : v) {
			int nx = x + dx;
			int ny = y + dy;
			if (nx < 0 or ny < 0 or nx >= n or ny >= n) continue;
			if (dis[nx][ny] != -1) continue;
			q.push({nx, ny});
			dis[nx][ny] = dis[x][y] + 1;
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << dis[i][j] << ' ';
		}
		cout << '\n';
	}
}

