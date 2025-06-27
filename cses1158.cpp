#include<bits/stdc++.h>
using namespace std;
int dp[1005][100005] = {};
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> w(n + 5), v(n + 5);
	for (int i = 1;i <= n;i++) {
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= x;j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[n][x];
}

