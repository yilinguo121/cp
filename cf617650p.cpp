#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const string INF = "{";
int main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	for (auto &x : v) cin >> x;
	vector<string> dp(k + 1, INF);
	dp[0] = "";
	for (int i = n - 1;i >= 0;i--) {
		vector<string> ndp = dp;
		for (int j = 1;j <= k;j++) {
			if (dp[j - 1] == INF) continue;
			ndp[j] = min(v[i] + dp[j - 1], ndp[j]);
		}
		dp = ndp;
	}
	cout << dp[k];
}
