#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	dp[0][0] = 1;
	for (int i = 0;i <= n;i++) {
		for (int j = 0;j <= m;j++) {
			if ((abs(i - x) == 1 and abs(j - y) == 2) or (abs(i - x) == 2 and abs(j - y) == 1) or (i == x and j == y)) continue;
			dp[i][j] = dp[i][j] + (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
		}
	}
	cout << dp[n][m];
}
