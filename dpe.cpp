#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, t;
	cin >> n >> t;
	int sum = 0;
	int w[101], v[101];
	for (int i = 1;i <= n;i++) {
		cin >> w[i] >> v[i];
		sum += v[i];
	}
	vector<long long> dp(sum + 1,1000000000);
	dp[0] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = sum;j >= v[i];j--) {
			dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	int ans = 0;
	for (int i = 1;i <= sum;i++) {
		if (dp[i] <= t) ans = i;
	}
	cout << ans;
}


