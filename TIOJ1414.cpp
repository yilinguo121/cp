#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int m, n;
	int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
	while (cin >> m >> n) {
		string s[m];
		bool vis1[m][n] = {}, vis2[m][n] = {};
		int ans[2] = {};
		for (int i = 0;i < m;i++) cin >> s[i];
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < m;j++) {
				if (!vis1[i][j] and (s[i][j] == '1' or s[i][j] == '2')) {
					ans[0]++;
					queue<pair<int, int>> q;
					q.push({i, j});
					vis1[i][j] = 1;
					while (!q.empty()) {
						auto [x, y] = q.front();
						q.pop();
						for (int k = 0;k < 8;k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 or ny < 0 or nx >= m or ny >= n) continue;
							if (vis1[nx][ny] or s[nx][ny] == '0') continue;
							q.push({nx, ny});
							vis1[nx][ny] = 1;
						}
					}
				}
				if (!vis2[i][j] and s[i][j] == '2') {
					ans[1]++;
					queue<pair<int, int>> q;
					q.push({i, j});
					vis2[i][j] = 1;
					while (!q.empty()) {
						auto [x, y] = q.front();
						q.pop();
						for (int k = 0;k < 8;k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 or ny < 0 or nx >= m or ny >= n) continue;
							if (vis2[nx][ny] or s[nx][ny] != '2') continue;
							q.push({nx, ny});
							vis2[nx][ny] = 1;
						}
					}
				}
			}
		}
		cout << ans[0] << ' ' << ans[1] << '\n';
	}
}
