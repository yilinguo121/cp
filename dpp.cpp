#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long mod = 1000000007;
vector<vector<int>> v, dp;
vector<bool> vis;
void dfs(int t) {
	vis[t] = 1;
	for (auto nt : v[t]) {
		if (vis[nt]) continue;
		dfs(nt);
		dp[0][t] = (dp[0][t] * (dp[0][nt] + dp[1][nt]) % mod) % mod;
		dp[1][t] = dp[1][t] * dp[0][nt] % mod;
	}
}
signed main() {
	int n;
	cin >> n;
	v.resize(n + 1);
	dp.assign(2, vector<int>(n + 1, 1));
	vis.resize(n + 1);
	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << (dp[0][1] + dp[1][1]) % mod;
}
