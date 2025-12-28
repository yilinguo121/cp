#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<string> a;
bool vis[200][200], add_vis[200][200];
int ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x, int y) {
	vis[x][y] = 1;
	for (int i = 0;i < 4;i++) {
		int nx = x;
		int ny = y;
		do {
			if (!add_vis[nx][ny]) ans++, add_vis[nx][ny] = 1;
			nx += dx[i];
			ny += dy[i];
		} while (a[nx][ny] != '#');
		nx -= dx[i];
		ny -= dy[i];
		if (!vis[nx][ny]) dfs(nx, ny);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	a.resize(n);
	for (auto &x : a) cin >> x;
	dfs(1, 1);
	cout << ans;
}

