#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	dp[0] = 0;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		for (int j = i - 1;j >= 0;j--) {
			if (dp[j] < 0) continue;
			dp[j + 1] = max(dp[j + 1], dp[j] + x);
		}
	}
	for (int i = n;i >= 0;i--) {
		if (dp[i] >= 0) {
			cout << i;
			return 0;
		}
	}
}

