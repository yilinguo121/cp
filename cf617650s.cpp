#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n + 1), pre(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -INF / 2));
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		dp[i][i] = v[i];
		pre[i] = pre[i - 1] + v[i];
	}
	for (int i = n;i >= 1;i--) {
		for (int j = i + 1;j <= n;j++) {
			dp[i][j] = max({dp[i][j], (dp[i + 1][j] != -INF / 2 ? pre[j] - pre[i - 1] - dp[i + 1][j] : -INF / 2), (dp[i][j - 1] != -INF / 2 ? pre[j] - pre[i - 1] - dp[i][j - 1] : -INF / 2)});
		}
	}
	cout << dp[1][n];
}
