#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = 2e9;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> dp(n + 2, INF);
		vector<int> v(k);
		for (auto &x : v) cin >> x;
		for (int i = 0;i < k;i++) {
			int x;
			cin >> x;
			dp[v[i]] = x;
		}
		for (int i = 1;i <= n;i++) dp[i] = min(dp[i - 1] + 1, dp[i]);
		for (int i = n;i >= 1;i--) dp[i] = min(dp[i + 1] + 1, dp[i]);
		for (int i = 1;i <= n;i++) cout << dp[i] << ' ';
		cout << '\n';
	}
}

