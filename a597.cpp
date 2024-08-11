#include <bits/stdc++.h>
using namespace std;
string arr[505] = {};
bool vis[505][505] = {};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
int bfs(int x, int y) {
	int t = 0;
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = 1;
	while (!q.empty()) {
		auto [x, y] = q.front();
		t++;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (ny < 0 or nx < 0 or ny >= m or nx >= n) continue;
			if (arr[nx][ny] == 'X') continue;
			if (vis[nx][ny]) continue;
			q.push({nx, ny});
			vis[nx][ny] = 1;
		}
	}
	return t;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin >> n >> m) {
        int ans = 0, tot = 0;
        for(int i = 0; i < n; ++i) {
			cin >> arr[i];
        }
		memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(arr[i][j] == 'J' and !vis[i][j]) {
                    int sz = bfs(i, j);
                    ans = max(ans, sz);
                    tot++;
                }
            }
        }
        cout << tot << ' ' << ans << '\n';
    }
}
