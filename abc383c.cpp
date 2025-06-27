#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int h, w, d;
	cin >> h >> w >> d;
	queue<pair<int, int>> q;
	bool vis[h][w] = {};
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	char s[h][w];
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			cin >> s[i][j];
			if (s[i][j] == 'H') q.push({i, j});
		}
	}
	int ans = q.size();
	int step = 0;
	while (!q.empty() and step < d) {
		int sz = q.size();
		for (int j = 0;j < sz;j++) {
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0;i < 4;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if ((nx < 0 or nx >= h or ny < 0 or ny >= w) or s[nx][ny] != '.' or vis[nx][ny]) continue;
				q.push({nx, ny});
				vis[nx][ny] = 1;
				ans++;
			}
		}
		step++;
	}
	cout << ans;
}

