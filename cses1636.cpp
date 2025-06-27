#include<bits/stdc++.h>
using namespace std;
int dp[105][1000005] = {};
signed main() {
	int n, x, mod = 1e9 + 7;
	cin >> n >> x;
	vector<int> c(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> c[i];
	}
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= x;j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= c[i]) {
				dp[i][j] = (1ll * dp[i][j] + dp[i][j - c[i]]) % mod;
			}
		}
	}
	cout << dp[n][x];
}
