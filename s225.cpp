#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> p(k);
	for (auto &x : p) cin >> x;
	vector<vector<int>> dp(k + 1, vector<int>(k + 1, INF)), v(n + 1, vector<int>(n + 1));
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) cin >> v[i][j];
	dp[1][0] = v[1][p[0]];
	for (int i = 1;i < k;i++) for (int j = 0;j < i;j++) {
		if (dp[i][j] == INF) continue;
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + v[p[i - 1]][p[i]]);
		dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + v[(j == 0 ? 1 : p[j - 1])][p[i]]);
	}
	int ans = INF;
	for (int i = 0;i < k;i++) ans = min(ans, dp[k][i] + v[p[k - 1]][n] + v[(i == 0 ? 1 : p[i - 1])][n]);
	cout << ans;
}
