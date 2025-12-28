#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1), dp(n + 1), mp(n + 1);
	for (int i = 1;i <= n;i++) cin >> v[i];
	while (m--) {
		int a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	for (int i = 1;i <= n;i++) {
		auto now = dp;
		for (int j = 0;j < i;j++) {
			now[0] = max(now[0], dp[j]);
			now[j + 1] = max(now[j + 1], dp[j] + v[i] + mp[j + 1]);
		}
		dp = now;
	}
	cout << *max_element(dp.begin(), dp.end());
}
