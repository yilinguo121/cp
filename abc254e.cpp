#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<bool> vis;
int n, m, k, ans, q;
vector<vector<int>> v;
void dfs(int t, int cnt) {
	if (!vis[t]) ans += t;
	vis[t] = 1;
	for (auto nt : v[t]) {
		if (cnt + 1 > k) return;
		dfs(nt, cnt + 1);
	}
}
signed main() {
	cin >> n >> m;
	v.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cin >> q;
	while (q--) {
		vis.clear();
		vis.resize(n + 1);
		int x;
		cin >> x >> k;
		ans = 0;
		dfs(x, 0);
		cout << ans << '\n';
	}
}

