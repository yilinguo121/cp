#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
const long long mod = 1000000007;
vector<vector<int>> dp;
int main() {
	IO;
	int n, x;
	cin >> n >> x;
	dp.resize(n + 1, vector<int>(x + 1));
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++) {
		int t;
		cin >> t;
		for (int j = 0;j <= x;j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= t) dp[i][j] = (dp[i][j] + dp[i][j - t]) % mod;
		}
	}
	cout << dp[n][x];
}
