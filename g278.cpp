#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(k + 2, vector<int>(n + 2));
	vector<bool> vis(100001);
	vector<int> v(n), len(n);
	for (auto &x : v) cin >> x;
	for (int l = 0, r = -1;l < n;l++) {
		while (r + 1 < n and !vis[v[r + 1]]) r++, vis[v[r]] = 1;
		len[l] = r - l + 1;
		vis[v[l]] = 0;
		dp[1][r] = max(dp[1][r], len[l]);
	}
	for (int i = 1;i <= k;i++) {
		dp[i][i - 1] = i;
		for (int j = i;j < n;j++) {
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			dp[i + 1][j + len[j] - 1] = max(dp[i + 1][j + len[j] - 1], dp[i][j - 1] + len[j]);
		}
	}
	cout << dp[k][n - 1];
}
