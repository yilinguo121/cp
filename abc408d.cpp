#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<vector<int>> dp(3, vector<int> (n + 1, INF));
		dp[0][0] = 0;
		for (int i = 1;i <= n;i++) {
			dp[0][i] = dp[0][i - 1] + (s[i - 1] == '1' ? 1 : 0);
			dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + (s[i - 1] == '0' ? 1 : 0);
			dp[2][i] = min(dp[1][i - 1], dp[2][i - 1]) + (s[i - 1] == '1' ? 1 : 0);
		}
		cout << min({dp[0][n], dp[1][n], dp[2][n]}) << '\n';
	}
}
