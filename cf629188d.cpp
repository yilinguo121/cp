#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v;
int ans = 0, m, n;
vector<vector<bool>> vis;
void dfs(int i, int j) {
	if (i >= m) {
		ans++;
		return;
	}
	if (j >= n) {
		dfs(i + 1, 0);
		return;
	}
	if (vis[i][v[i][j]]) {
		dfs(i, j + 1);
		return;
	}
	if (j + 1 < n and !vis[i][v[i][j + 1]]) {
		dfs(i, j + 2);
	}
	if (i + 1 < m) {
		vis[i + 1][v[i][j]] = 1;
		dfs(i, j + 1);
		vis[i + 1][v[i][j]] = 0;
	}
}
signed main() {
	IO
	cin >> m >> n;
	v.resize(m, vector<int> (n));
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) cin >> v[i][j];
	}
	vis.resize(m + 1, vector<bool> (n + 1));
	dfs(0, 0);
	cout << ans;
}

