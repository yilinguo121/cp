#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<string> s(n);
	for (auto &x : s) cin >> x;
	vector<vector<int>> dp(n, vector<int>(m));
	dp[0][0] = 1;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (!i and !j) continue;
			if (s[i][j] == '.') dp[i][j] = ((i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0)) % 998244353;
		}
	}
	cout << dp[n - 1][m - 1] % 998244353;
}

