#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const long long mod = 1000000007;
signed main() {
	IO
	vector<vector<int>> dp(5001, vector<int>(5001));
	dp[0][0] = 1;
	for (int i = 1;i <= 5000;i++) for (int j = 1;j <= 5000;j++) dp[i][j] = (j * dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << dp[n][k] << '\n';
	}
}
