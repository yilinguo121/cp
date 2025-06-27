#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int a[m + 5][n + 5], s[m + 5][n + 5];
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> a[i][j];
			s[i][j] = a[i][j];
			if (j <= 0) continue;
			s[i][j] += s[i][j - 1];
		}
	}
	int dp[m + 5][n + 5][n + 5] = {};
	int ans = -1e9;
	for (int l = 1;l <= n;l++) {
		for (int r = l;r <= n;r++) {
			for (int i = 1;i <= m;i++) {
				dp[i][l][r] = max(dp[i - 1][l][r] + s[i][r] - s[i][l - 1], s[i][r] - s[i][l - 1]);
				ans = max(ans, dp[i][l][r]);
			}
		}
	}
	cout << ans;
}
