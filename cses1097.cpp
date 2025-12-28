#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n + 1), pre(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		pre[i] = pre[i - 1] + v[i];
		dp[i][i] = v[i];
	}
	for (int l = n;l >= 1;l--) {
		for (int r = l + 1;r <= n;r++) {
			dp[l][r] = max(pre[r] - pre[l - 1] - dp[l + 1][r], pre[r] - pre[l - 1] - dp[l][r - 1]);
		}
	}
	cout << dp[1][n];
}
