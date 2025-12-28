#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<vector<int>> dp(n, vector<int>(n + 1));
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	int ans = 0;
	for (int l = n - 1;l >= 0;l--) {
		for (int r = l + 1;r < n;r++) {
			dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + v[r] - v[l];
		}
	}
	cout << dp[0][n - 1];
}

