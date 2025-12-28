#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	for (int i = 0;i <= m;i++) dp[i][0] = 1;
	for (int i = 1;i <= m;i++) {
		dp[i] = dp[i - 1];
		for (int j = 1;j <= n;j++) {
			if (a[j - 1] == b[i - 1]) dp[i][j] += dp[i - 1][j - 1];
		}
	}
	cout << dp[m][n];
}
