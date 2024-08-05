#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> h(2);
	int t;
	while(cin >> h[0] >> h[1] >> t) {
		vector<int> dp(t + 1, -1e9);
		dp[0] = 0;
		for (int i = 1;i <= t;i++) {
			if (i >= h[0]) {
				dp[i] = max(dp[i], dp[i - h[0]] + 1);
			}
			if (i >= h[1]) {
				dp[i] = max(dp[i], dp[i - h[1]] + 1);
			}
		}
		if (dp[t] < 0) {
			for (int i = t - 1;i >= 0;i--) {
				if (dp[i] >= 0) {
					cout << dp[i] << ' ' << t - i;
					break;
				}
			}
		}
		else {
			cout << dp[t];
		}
		cout << '\n';
	}
}
