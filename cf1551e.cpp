#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> dp(n + 1, -INF);
		dp[0] = 0;
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			for (int j = i;j >= 0;j--) {
				if (dp[j] == -INF) continue;
				dp[j + 1] = max(dp[j + 1], dp[j] + (x == j + 1));
			}
		}
		int ans = -1;
		for (int i = 0;i <= n;i++) {
			if (dp[i] >= k) ans = n - i;
		}
		cout << ans << '\n';
	}
}
