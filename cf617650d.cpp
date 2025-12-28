#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
long long ans;
vector<vector<pair<int, bool>>> v;
vector<bool> vis[2];
void dfs(int t, bool now) {
	if (!vis[0][t] and !vis[1][t]) ans++;
	vis[now][t] = 1;
	for (auto [nt, x] : v[t]) {
		if (vis[now or x][nt]) continue;
		if (now and x) continue;
		dfs(nt, x or now);
	}
}
int main() {
	IO
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	vis[0].resize(n + 1);
	vis[1].resize(n + 1);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	for (int i = 1;i <= n;i++) {
		for (int i = 1;i <= n;i++) vis[0][i] = 0, vis[1][i] = 0;
		dfs(i, 0);
	}
	cout << ans;
}
