#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0;i < n;i++) cin >> a[i];
	int ans = -INF;
	for (int start = 0;start < n;start++) {
		vector<int> b(n), pre(n + 1);
		for (int i = 0;i < n;i++) {
			b[i] = a[(i + start) % n];
			pre[i + 1] = pre[i] + b[i];
		}
		vector<vector<int>> dp(n, vector<int>(n, -INF));
		for (int i = 0;i < n;i++) dp[i][i] = 0;
		for (int len = 2;len <= n;len++) for (int l = 0;l + len - 1 < n;l++) {
			int r = l + len - 1;
			for (int k = l;k < r;k++) dp[l][r] = max(dp[l][r], llabs((pre[k + 1] - pre[l]) - (pre[r + 1] - pre[k + 1])) - max(dp[l][k], dp[k + 1][r]));
		}
		ans = max(ans, dp[0][n - 1]);
	}
	cout << ans;
}

