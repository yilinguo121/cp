#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
vector<vector<int>> v, dp;
vector<bool> vis;
void dfs(int t) {
	vis[t] = 1;
	int sum = 0;
	vector<int> a;
	for (auto nt : v[t]) {
		if (vis[nt]) continue;
		dfs(nt);
		a.push_back(nt);
		sum += dp[0][nt];
	}
	dp[1][t] = dp[0][t] = sum;
	for (auto nt : a) dp[0][t] = max(dp[0][t], sum - dp[0][nt] + 1 + dp[1][nt]);
}
int main() {
	int n;
	cin >> n;
	v.resize(n + 1);
	dp.resize(2, vector<int> (n + 1));
	vis.resize(n + 1);
	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << dp[0][1];
}
