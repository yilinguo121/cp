#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool vis[33][33];
int ans[33][2], sum = 0;;
void dfs(int x, int y, int cnt) {
	if (x == n and y == m) {
		for (int i = 0;i < cnt;i++) cout << "(" << ans[i][0] << "," << ans[i][1] << ")" << (i == cnt - 1 ? "\n" : "-");
		sum++;
	}
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 or ny < 1 or nx > n or ny > m) continue;
		if (vis[nx][ny]) continue;
		vis[nx][ny] = 1;
		ans[cnt][0] = nx;
		ans[cnt][1] = ny;
		dfs(nx, ny, cnt + 1);
		vis[nx][ny] = 0;
	}
}
int main() {
	cin >> n >> m;
	ans[0][0] = 1;
	ans[0][1] = 1;
	vis[1][1] = 1;
	dfs(1, 1, 1);
	cout << "total path num: " << sum;
}
