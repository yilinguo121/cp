#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
	}
	vector<vector<int>> dp(1 << n, vector<int>(n));
	dp[1][0] = 1;
	for (int i = 1;i < (1 << n);i += 2) {
		for (int t = 0;t < n;t++) {
			if (!dp[i][t]) continue;
			for (auto nt : v[t]) {
				if (i & (1 << nt)) continue;
				dp[i | (1 << nt)][nt] = (dp[i | (1 << nt)][nt] + dp[i][t]) % 1000000007;
			}
		}
	}
	cout << dp[(1 << n) - 1][n - 1];
}

