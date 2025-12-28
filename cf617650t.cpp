#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	v.insert(v.end(), v.begin(), v.end());
	v.push_back(v[0]);
	vector<vector<int>> dp(2 * n, vector<int>(2 * n));
	for (int i = 2 * n - 1;i >= 0;i--) {
		for (int j = i + 1;j < 2 * n and j - i + 1 <= n;j++) {
			for (int k = i;k < j;k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i] * v[k + 1] * v[j + 1]);
			}
		}
	}
	int ans = 0;
	for (int i = 0;i < n;i++) ans = max(ans, dp[i][i + n - 1]);
	cout << ans;
}
