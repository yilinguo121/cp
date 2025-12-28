#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int x, y;
	cin >> x >> y;
	vector<int> dp(10);
	dp[0] = x;
	dp[1] = y;
	for (int i = 2;i < 10;i++) {
		string s = to_string(dp[i - 1] + dp[i - 2]);
		reverse(s.begin(), s.end());
		dp[i] = stoll(s);
	}
	cout << dp.back();
}

