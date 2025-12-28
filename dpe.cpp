#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = 1e13;
#define int long long
signed main() {
	int n, m;
	cin >> n >> m;
	vector<int> dp(100001, INF);
	dp[0] = 0;
	while (n--) {
		int w, v;
		cin >> w >> v;
		for (int i = 100000;i >= 1;i--) if (i >= v) dp[i] = min(dp[i], dp[i - v] + w);
	}
	for (int i = 100000;i >= 0;i--) {
		if (dp[i] <= m) {
			cout << i;
			return 0;
		}
	}
}

