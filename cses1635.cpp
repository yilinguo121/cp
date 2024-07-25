#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, x;
	int mod = 1e9 + 7;
	cin >> n >> x;
	int c[n];
	for (int i = 0;i < n;i++) {
		cin >> c[i];
	}
	vector<int> dp(x + 5);
	dp[0] = 1;
	for (int j = 1;j <= x;j++) {
		for (int i = 0;i < n;i++) {
			if (j >= c[i]) {
				dp[j] += dp[j - c[i]];
				dp[j] = dp[j] % mod;
			}
		}
	}
	cout << dp[x];
}
