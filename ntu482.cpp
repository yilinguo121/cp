#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	vector<vector<int>> dp(2, vector<int> (n, -INF));
	dp[1][0] = v[0];
	for (int i = 1;i < n;i++) {
		dp[1][i] = dp[0][i - 1] + v[i];
		dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
	}
	cout << dp[1][n - 1];
}
