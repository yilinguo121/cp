#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int p, q, r, m;
vector<int> a;
vector<vector<int>> pa;
vector<bool> vis;
vector<pair<int, int>> dp;
pair<int, int> dfs(int t) {
	if (t <= p) {
		vis[t] = 1;
		return dp[t] = {a[t], 0};
	}
	if (t >= p + q + 1 and t <= p + q + r) return dfs(pa[t][0]);
	if (vis[t]) return dp[t];
	vis[t] = 1;
	auto x = dfs(pa[t][0]);
	if (a[t] == 4) return dp[t] = make_pair(!x.first, x.second + 1);
	auto y = dfs(pa[t][1]);
	if (a[t] == 1) return dp[t] = make_pair(x.first and y.first, max(x.second, y.second) + 1);
	if (a[t] == 2) return dp[t] = make_pair(x.first or y.first, max(x.second, y.second) + 1);
	if (a[t] == 3) return dp[t] = make_pair(x.first xor y.first, max(x.second, y.second) + 1);
}
int main() {
	IO
	cin >> p >> q >> r >> m;
	a.resize(p + q + 1);
	pa.resize(p + q + r + 1);
	dp.resize(p + q + r + 1);
	vis.resize(p + q + r + 1);
	for (int i = 1;i <= p + q;i++) cin >> a[i];
	while (m--) {
		int x, y;
		cin >> x >> y;
		pa[y].push_back(x);
	}
	int ans = 0;
	vector<int> out;
	for (int i = p + q + 1;i <= p + q + r;i++) {
		auto [x, y] = dfs(i);
		out.push_back(x);
		ans = max(ans, y);
	}
	cout << ans << '\n';
	for (auto x : out) cout << x << ' ';
}

