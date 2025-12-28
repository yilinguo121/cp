#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF / 2));
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (i == j) dp[i][j] = 0;
			else {
				for (int k = 1;k < i;k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
				for (int k = 1;k < j;k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
			}
		}
	}
	cout << dp[n][m];
}
