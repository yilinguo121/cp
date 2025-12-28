#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(k), dp(n + 1);
	for (auto &x : v) cin >> x;
	for (int i = 1;i <= n;i++) {
		for (auto x : v) {
			if (i < x) break;
			dp[i] = max(dp[i], x + ((i - x) - dp[i - x]));
		}
	}
	cout << dp[n];
}
