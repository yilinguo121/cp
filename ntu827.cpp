#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long mod = 1000000007;
vector<vector<int>> v, dp;
vector<bool> vis;
int n;
void dfs(int t) {
	vis[t] = 1;
	for (auto nt : v[t]) {
		if (vis[nt]) continue;
		dfs(nt);
		for (int i = 0;i < 3;i++) dp[t][i] = (dp[t][i] * (dp[nt][(i + 1) % 3] + dp[nt][(i + 2) % 3]) % mod) % mod;
	}
}
signed main() {
	cin >> n;
	v.resize(n + 1);
	vis.resize(n + 1);
	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dp.assign(n + 1, vector<int>(3, 1));
	dfs(1);
	cout << (dp[1][0] + dp[1][1] + dp[1][2]) % mod << '\n';
}
