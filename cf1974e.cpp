#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = (1ll << 60);
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> c(n + 1), h(n + 1), dp(100001, INF);
		for (int i = 1;i <= n;i++) cin >> c[i] >> h[i];
		dp[0] = 0;
		int m = 0;
		for (int i = 1;i <= n;i++) {
			for (int j = m;j >= 0;j--) {
				dp[j + h[i]] = min(dp[j + h[i]], dp[j] + c[i]);
			}
			m += h[i];
			for (auto &t : dp) if (t > (i - 1) * x) t = INF;
		}
		for (int i = 100000;i >= 0;i--) {
			if (dp[i] != INF) {
				cout << i << '\n';
				break;
			}
		}
	}
}
