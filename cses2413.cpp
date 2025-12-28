#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
const long long mod = 1000000007;
signed main() {
	IO
	int t;
	cin >> t;
	vector<vector<int>> dp(2, vector<int>(1000001));
	dp[0][1] = dp[1][1] = 1;
	for (int i = 2;i <= 1000000;i++) {
		dp[0][i] = (dp[0][i - 1] % mod + dp[0][i - 1] % mod + dp[1][i - 1] % mod) % mod;
		dp[1][i] = (4 * dp[1][i - 1] % mod + dp[0][i - 1]) % mod;
	}
	while (t--) {
		int n;
		cin >> n;
		cout << (dp[0][n] + dp[1][n]) % mod << '\n';
	}
}

