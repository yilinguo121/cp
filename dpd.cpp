#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, x;
	cin >> n >> x;
	vector<int> dp(x + 1);
	while (n--) {
		int w, v;
		cin >> w >> v;
		for (int i = x;i >= w;i--) dp[i] = max(dp[i], dp[i - w] + v);
	}
	cout << dp[x];
}
