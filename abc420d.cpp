#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	pair<int, int> st;
	for (int i = 0;i < n;i++) {
		cin >> s[i];
		for (int j = 0;j < m;j++) {
			if (s[i][j] == 'S') st = make_pair(i, j);
		}
	}
	queue<tuple<int, int, bool, int>> q;
	q.push({st.first, st.second, 0, 0});
	bool vis[2][n][m] = {};
	vis[0][st.first][st.second] = 1;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	while (!q.empty()) {
		auto [x, y, flag, cnt] = q.front();
		q.pop();
		if (s[x][y] == 'G') {
			cout << cnt;
			return 0;
		}
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
			if (s[nx][ny] == '#' or (flag and s[nx][ny] == 'o') or (!flag and s[nx][ny] == 'x')) continue;
			if (s[nx][ny] == '?') {
				if (vis[!flag][nx][ny]) continue;
				q.push({nx, ny, !flag, cnt + 1});
				vis[!flag][nx][ny] = 1;
			}
			else {
				if (vis[flag][nx][ny]) continue;
				q.push({nx, ny, flag, cnt + 1});
				vis[flag][nx][ny] = 1;
			}
		}
	}
	cout << -1;
}

