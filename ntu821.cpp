#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max() / 2;
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (auto &x : v) cin >> x;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
	for (int i = 0;i <= n;i++) dp[i][i] = 0;
	for (int l = n;l >= 1;l--) {
		for (int r = l + 1;r <= n;r++) {
			for (int k = l;k < r;k++) {
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + v[l - 1] * v[k] * v[r]);
			}
		}
	}
	cout << dp[1][n];
}
