#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	vector<vector<int>> dis(n, vector<int>(m, INF));
	queue<tuple<int, int, int>> q; // 存入 x座標 / y座標 / 步數
	pair<int, int> raymond, fbi;
	for (int i = 0;i < n;i++) for (int j = 0;j < m;j++) {
		cin >> v[i][j];
		if (v[i][j] == 'F') fbi = {i, j};
		if (v[i][j] == 'R') raymond = {i, j};
	}
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
	q.push({fbi.first, fbi.second, 0});
	dis[fbi.first][fbi.second] = 0;
	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
			if (v[nx][ny] == '#') continue;
			if (cnt < dis[nx][ny]) {
				q.push({nx, ny, cnt + 1});
				dis[nx][ny] = cnt;
			}
		}
	}
	q.push({raymond.first, raymond.second, 0});
	while (!q.empty()) {
		auto [x, y, cnt] = q.front();
		q.pop();
		if (v[x][y] == 'X') {
			cout << "Yes";
			return 0;
		}
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
			if (v[nx][ny] == '#') continue;
			if (cnt < dis[nx][ny]) {
				q.push({nx, ny, cnt + 1});
				dis[nx][ny] = cnt;
			}
		}
	}
	cout << "No";
}
