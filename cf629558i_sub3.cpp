#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> a(n), pre(2 * n + 1);
	for (auto &x : a) cin >> x;
	a.insert(a.end(), a.begin(), a.end());
	vector<vector<int>> dp(2 * n, vector<int>(2 * n, -INF));
	for (int i = 0;i < 2 * n;i++) dp[i][i] = 0;
	for (int i = 0;i < 2 * n;i++) pre[i + 1] = pre[i] + a[i];
	for (int len = 2;len <= n;len++) {
		for (int l = 0;l + len - 1 < 2 * n;l++) {
			int r = l + len - 1;
			for (int k = l;k < r;k++) dp[l][r] = max(dp[l][r], llabs((pre[k + 1] - pre[l]) - (pre[r + 1] - pre[k + 1])) - max(dp[l][k], dp[k + 1][r]));
		}
	}
	int ans = -INF;
	for (int i = 0;i + n - 1 < 2 * n;i++) ans = max(ans, dp[i][i + n - 1]);
	cout << ans;
}
