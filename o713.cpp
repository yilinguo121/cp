#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int m, n, t;
int start_x, start_y;
int a[500][500] = {};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool bfs(int mid) {
	queue<tuple<int, int, int>> q;
	q.push({start_x, start_y, mid});
	int cnt = 1;
	int vis[m][n] = {};
	vis[start_x][start_y] = mid + 1;
	while (!q.empty()) {
		if (cnt >= t) break;
		auto [x, y, l] = q.front();
		q.pop();
		if (!l) continue;
		for (int k = 0;k < 4;k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 or ny < 0 or nx >= m or ny >= n) continue;
			if (max(l - 1, a[nx][ny]) <= vis[nx][ny] - 1) continue;
			if (a[nx][ny] == -1) continue;
			q.push({nx, ny, max(l - 1, a[nx][ny])});
			if (!vis[nx][ny]) cnt++;
			vis[nx][ny] = max(l - 1, a[nx][ny]) + 1;
		}
	}
	return cnt >= t;
}
int main() {
	IO
	cin >> m >> n >> t;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[i][j];
			if (a[i][j] == -2) {
				start_x = i;
				start_y = j;
			}
		}
	}
	int l = 0, r = m * n, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (bfs(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else l = mid + 1;
	}
	cout << ans;
}

