#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
const long long mod = 998244353;
signed main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n + 1, vector<char>(m + 1));
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(m + 1)));
	dp[0][1][0] = 1;
	for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) {
		cin >> v[i][j];
		if (v[i][j] == '#') {
			dp[0][i][j] = (dp[1][i - 1][j] + dp[1][i][j - 1]) % mod;
			dp[1][i][j] = (dp[0][i - 1][j] + dp[0][i][j - 1]) % mod;
		}
		else {
			dp[0][i][j] = (dp[0][i - 1][j] + dp[0][i][j - 1]) % mod;
			dp[1][i][j] = (dp[1][i - 1][j] + dp[1][i][j - 1]) % mod;
		}
	}
	cout << dp[1][n][m] % mod;
}
