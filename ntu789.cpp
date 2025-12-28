#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max() / 2;
int main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 2, vector<int>(m + 2, -INF)));
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	for (int i = 1;i <= n;i++) for (int j = 1;j <= m;j++) cin >> v[i][j];
	for (int i = 0;i <= n + 1;i++) dp[1][i][0] = dp[1][i][m + 1] = dp[0][i][0] = dp[0][i][m + 1] = 0;
	for (int j = 0;j <= m + 1;j++) dp[1][0][j] = dp[1][n + 1][j] = dp[0][0][j] = dp[0][n + 1][j] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			dp[0][i][j] = max({dp[0][i][j], max(dp[0][i - 1][j], dp[1][i - 1][j]) + v[i][j], dp[0][i][j - 1] + v[i][j]});
		}
		for (int j = m;j >= 1;j--) {
			dp[1][i][j] = max({dp[1][i][j], max(dp[0][i - 1][j], dp[1][i - 1][j]) + v[i][j], dp[1][i][j + 1] + v[i][j]});
		}
	}
	cout << max(*max_element(dp[0][n].begin(), dp[0][n].end()), *max_element(dp[1][n].begin(), dp[1][n].end()));
}
