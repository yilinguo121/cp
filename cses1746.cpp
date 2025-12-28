#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const int mod = 1000000007;
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 2));
	int a1;
	cin >> a1;
	if (!a1) for (int i = 1;i <= m;i++) dp[1][i] = 1;
	else dp[1][a1] = 1;
	for (int i = 2;i <= n;i++) {
		int x;
		cin >> x;
		if (!x) {
			for (int j = 1;j <= m;j++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
				dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
				dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			}
		}
		else {
			dp[i][x] = dp[i - 1][x];
			if (x > 1) dp[i][x] = (dp[i][x] + dp[i - 1][x - 1]) % mod;
			if (x < m) dp[i][x] = (dp[i][x] + dp[i - 1][x + 1]) % mod;
		}
	}
	int ans = 0;
	for (int i = 1;i <= m;i++) ans = (ans + dp[n][i]) % mod;
	cout << ans;
}
