#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
bool vis[1048577][1001];
int ans = INF, n, m;
vector<vector<pair<int, int>>> v;
void dfs(int t, int now) {
	if (t == n) ans = min(ans, now);
	vis[now][t] = 1;
	for (auto [nt, w] : v[t]) {
		if (vis[now ^ w][nt]) continue;
		dfs(nt, now ^ w);
	}
}
int main() {
	cin >> n >> m;
	v.resize(n + 1);
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w});
	}
	dfs(1, 0);
	cout << (ans == INF ? -1 : ans);
}
