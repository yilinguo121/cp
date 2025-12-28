#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const long long mod = 1000000007;
signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) cin >> b[i];
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
			dp[i][j] = (dp[i][j] + mod) % mod;
		}
	}
	cout << (dp[n][m] + 1) % mod;
}
