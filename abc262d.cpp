#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) cin >> v[i];
	int ans = 0;
	for (int m = 1;m <= n;m++) {
		vector<vector<int>> dp(m + 1, vector<int>(m));
		dp[0][0] = 1;
		for (int i = 1;i <= n;i++) {
			for (int j = m;j >= 1;j--) {
				for (int k = 0;k < m;k++) {
					dp[j][(k + v[i]) % m] = (dp[j][(k + v[i]) % m] + dp[j - 1][k]) % 998244353;
				}
			}
		}
		ans = (ans + dp[m][0]) % 998244353;
	}
	cout << ans;
}
