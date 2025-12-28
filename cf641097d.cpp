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
	vector<vector<int>> dp(n, vector<int>(n, -INF));
	for (int l = n - 1;l >= 0;l--) {
		for (int r = l + 2;r < n;r++) {
			for (int k = l + 1;k < r;k++) {
				dp[l][r] = max(dp[l][r], ((dp[l][k] == -INF ? 0 : dp[l][k]) + (dp[k][r] == -INF ? 0 : dp[k][r]) + v[l] * v[r]));
			}
		}
	}
	cout << dp[0][n - 1] << '\n';
}
