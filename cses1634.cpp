#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, x;
	int inf = 1e9;
	cin >> n >> x;
	vector<int> v(n + 5), dp(x + 5, inf);
	for (int i = 0;i < n;i ++) {
		cin >> v[i];
	}
	dp[0] = 0;
	for (int i = 1;i <= x;i++) {
		for (int j = 0;j < n;j++) {
			if (i >= v[j]) {
				dp[i] = min(dp[i], dp[i - v[j]] + 1);
			}
		}
	}
	if (dp[x] == inf) {
		cout << -1;
	}
	else {
		cout << dp[x];
	}
}
