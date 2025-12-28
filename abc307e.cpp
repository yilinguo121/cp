#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const long long mod = 998244353;
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(2, vector<int>(n + 1));
	dp[1][1] = m;
	for (int i = 2;i <= n;i++) {
		dp[0][i] = dp[0][i - 1] * (m - 2) % mod + dp[1][i - 1] * (m - 1) % mod;
		dp[1][i] = dp[0][i - 1];
	}
	cout << dp[0][n] % mod;
}

