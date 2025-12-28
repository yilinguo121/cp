#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n + 1), dp(n + 1);
		for (int i = 1;i <= n;i++) cin >> v[i];
		dp[0] = 1;
		for (int i = 1;i <= n;i++) {
			if (dp[i - 1] and i + v[i] <= n) dp[i + v[i]] = 1;
			if (i - v[i] >= 1 and dp[i - v[i] - 1]) dp[i] = 1;
		}
		cout << (dp[n] ? "YES\n" : "NO\n");
	}
}
