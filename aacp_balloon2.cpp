#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, k;
	cin >> n >> k;
	vector<int> v(k + 1), dp(k + 1);
	for (auto &x : v) cin >> x;
	for (int len = 2;len <= k + 1;len++) for (int i = 0;i + len - 1 <= k;i++) dp[i] = v[i + len - 1] - v[i] + max(dp[i], dp[i + 1]);
	cout << n + dp[0];
}
