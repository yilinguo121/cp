#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> dp(n + 1, -INF / 2);
		int ans = 0;
		for (int i = 1;i <= n;i++) {
			int x, last = ans;
			cin >> x;
			if (dp[x] != -INF / 2) ans = max(ans, dp[x] + i);
			dp[x] = max(dp[x], last - i + 1);
		}
		cout << ans << '\n';
	}
}

