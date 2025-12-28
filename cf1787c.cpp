#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		vector<int> x(n + 1), y(n + 1);
		for (int i = 1;i <= n;i++) {
			int k;
			cin >> k;
			if (i == 1 or i == n) x[i] = y[i] = k;
			else if (k <= s) {
				x[i] = k;
				y[i] = 0;
			}
			else {
				x[i] = k - s;
				y[i] = s;
			}
		}
		vector<vector<int>> dp(n + 1, vector<int>(2));
		dp[1][0] = dp[1][1] = 0;
		for (int i = 2;i <= n;i++) {
			dp[i][0] = min(dp[i - 1][0] + y[i - 1] * x[i], dp[i - 1][1] + x[i - 1] * x[i]);
			dp[i][1] = min(dp[i - 1][0] + y[i - 1] * y[i], dp[i - 1][1] + x[i - 1] * y[i]);
		}
		cout << min(dp[n][0], dp[n][1]) << '\n';
	}
}

