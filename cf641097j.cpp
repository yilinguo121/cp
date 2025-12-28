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
	vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1, -INF));
	for (int l = 2 * n - 1;l >= 0;l--) {
		for (int r = l + 2;r - l + 1 <= n + 1 and r < 2 * n;r++) {
			for (int k = l + 1;k < r;k++) {
				dp[l][r] = max(dp[l][r], ((dp[l][k] == -INF ? 0 : dp[l][k]) + (dp[k][r] == -INF ? 0 : dp[k][r]) + v[l] * v[r]));
			}
		}
	}
	int ans = -INF;
	for (int i = 0;i + (n - 1) < 2 * n;i++) ans = max(ans, dp[i][i + n]);
	cout << ans;
}
