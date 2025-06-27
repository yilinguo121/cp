#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int n;
	cin >> n;
	bool vis[n + 1][n + 1] = {};
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	queue<pair<int, int>> q;
	q.push({a, b});
	vis[a][b] = 1;
	int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
	int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		vis[x][y] = 1;
	}
	if (a == c and b == d) {
		cout << 0;
		return 0;
	}
	int ans = 0;
	while (!q.empty()) {
		int sz = q.size();
		ans++;
		while (sz--) {
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0;i < 8;i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 1 or ny < 1 or nx > n or ny > n) continue;
				if (vis[nx][ny]) continue;
				q.push({nx, ny});
				vis[nx][ny] = 1;
				if (nx == c and ny == d) {
					cout << ans;
					return 0;
				}
			}
		}
	}
	cout << "-1";
}

