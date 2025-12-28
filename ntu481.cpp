#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n + 1);
	vector<vector<int>> dp(2, vector<int>(n + 1));
	for (int i = 1;i <= n;i++) cin >> v[i];
	dp[1][1] = dp[0][1] = v[1];
	for (int i = 2;i <= n;i++) {
		dp[0][i] = dp[1][i - 1];
		dp[1][i] = max(dp[0][i - 1] + v[i], dp[1][i - 1] + v[i]);
	}
	cout << dp[1][n];
}
