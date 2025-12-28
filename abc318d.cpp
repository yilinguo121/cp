#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<bool> vis;
vector<vector<int>> v;
int n, ans = 0;
void dfs(int i, int now, int skip) {
	if (i == n) {
		ans = max(ans, now);
		return;
	}
	if (vis[i]) {
		dfs(i + 1, now, skip);
		return;
	}
	if (skip) dfs(i + 1, now, 0);
	for (int j = i + 1;j < n;j++) {
		if (vis[j]) continue;
		vis[i] = 1, vis[j] = 1;
		dfs(i + 1, now + v[i][j], skip);
		vis[i] = 0, vis[j] = 0;
	}
}
signed main() {
	cin >> n;
	vis.resize(n);
	v.resize(n, vector<int>(n));
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			cin >> v[i][j];
			v[j][i] = v[i][j];
		}
	}
	dfs(0, 0, n % 2);
	cout << ans;
}

