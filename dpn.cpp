#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF / 2));
	vector<int> v(n + 1), pre(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		pre[i] = pre[i - 1] + v[i];
		dp[i][i] = 0;
	}
	for (int l = n;l >= 1;l--) {
		for (int r = l + 1;r <= n;r++) {
			for (int k = l;k < r;k++) {
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
			}
		}
	}
	cout << dp[1][n];
}
