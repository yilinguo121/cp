#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	vector<vector<bool>> dp(2, vector<bool>(n));
	dp[0][0] = dp[1][0] = 1;
	for (int i = 1;i < n;i++) {
		if (abs(a[i] - a[i - 1]) <= k and !dp[0][i]) dp[0][i] = dp[0][i - 1];
		if (abs(a[i] - b[i - 1]) <= k and !dp[0][i]) dp[0][i] = dp[1][i - 1];
		if (abs(b[i] - a[i - 1]) <= k and !dp[1][i]) dp[1][i] = dp[0][i - 1];
		if (abs(b[i] - b[i - 1]) <= k and !dp[1][i]) dp[1][i] = dp[1][i - 1];
	}
	cout << (dp[0][n - 1] or dp[1][n - 1] ? "Yes" : "No");
}
