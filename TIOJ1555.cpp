#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int n, m;
	cin >> n >> m;
	vector<int> dp(m + 1);
	int sum = 0, ans = 0;
	for (int i = 1;i <= n;i++) {
		string s;
		cin >> s;
		vector<int> now(m + 1);
		for (int j = 1;j <= m;j++) {
			if (s[j - 1] == '1') continue;
			now[j] = min({dp[j], now[j - 1], dp[j - 1]}) + 1;
			sum += now[j];
			ans = max(now[j], ans);
		}
		dp = now;
	}
	cout << sum << ' ' << ans;
}
