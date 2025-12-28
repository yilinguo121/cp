#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<int> dp;
vector<vector<int>> v;
int dfs(int t) {
	if (dp[t] != -1) return dp[t];
	dp[t] = 0;
	for (auto nt : v[t]) dp[t] = max(dp[t], dfs(nt) + 1);
	return dp[t];
}
int main() {
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	dp.assign(n + 1, -1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) if (dp[i] == -1) ans = max(ans, dfs(i));
	cout << ans;
}
