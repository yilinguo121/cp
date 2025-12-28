#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	const int max_g = 10000000 / n;
	vector<vector<int>> dp(n + 1, vector<int>(max_g + 1, 0));
	vector<int> w(n), v(n);
	for (int i = 0;i < n;i++) cin >> w[i] >> v[i];
	for (int i = 1;i <= n;i++) {
		dp[i] = dp[i - 1];
		for (int g = 0;g <= max_g - w[i - 1];g++) {
			dp[i][g + w[i - 1]] = max(dp[i][g + w[i - 1]], dp[i - 1][g] + v[i - 1]);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int g;
		cin >> g;
		string ans(n, '0');
		for (int i = n;i > 0;i--) {
			if (dp[i][g] != dp[i - 1][g]) {
				ans[i - 1] = '1';
				g -= w[i - 1];
			}
		}
		cout << ans << '\n';
	}
}
