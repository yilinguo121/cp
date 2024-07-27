#include<bits/stdc++.h>
using namespace std;
int w[105], v[105], all = 0, dp[105][100005] = {};
int f(int n, int t) {
	dp[0][0] = 0;
	for (int i = 1;i < 100005;i++) {
		dp[0][i] = 1e9;
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= all;j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= v[i]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
			}
		}
	}
	for (int i = all;i >= 0;i--) {
		if (dp[n][i] <= t) {
			return i;
		}
	}
}
int main() {
	int n, t;
	cin >> n >> t;
	for (int i = 1;i <= n;i++) {
		cin >> w[i] >> v[i];
		all += v[i];
	}
	cout << f(n, t);
}
