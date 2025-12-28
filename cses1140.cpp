#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<array<int, 3>> v(n);
	for (auto &[x, y, w] : v) cin >> x >> y >> w;
	sort(v.begin(), v.end(), [](auto x, auto y) {
		if (x[1] == y[1]) return x[0] < y[0];
		return x[1] < y[1];
	});
	vector<int> a, dp(n + 1);
	for (auto [x, y, w] : v) a.push_back(y);
	for (int i = 1;i <= n;i++) {
		auto [x, y, w] = v[i - 1];
		dp[i] = max(dp[i - 1], dp[lower_bound(a.begin(), a.end(), x) - a.begin()] + w);
	}
	cout << dp[n];
}

