#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
char a[10][10];
int n, m, k, ans;
int vis[10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x, int y, int cnt) {
	if (cnt == k) {
		ans++;
		return;
	}
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
		if (a[nx][ny] == '#' or vis[nx][ny]) continue;
		vis[nx][ny] = 1;
		dfs(nx, ny, cnt + 1);
		vis[nx][ny] = 0;
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (a[i][j] == '#') continue;
			vis[i][j] = 1;
			dfs(i, j, 0);
			vis[i][j] = 0;
		}
	}
	cout << ans;
}

