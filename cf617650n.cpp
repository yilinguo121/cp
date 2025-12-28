#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = 9000000000000000000;
signed main() {
	IO
	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	dp[1] = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			string s;
			cin >> s;
			char c = s[0];
			int x = 0;
			for (int k = 1;k < s.size();k++) x = x * 10 + (s[k] - '0');
			if (dp[i] == -1) continue;
			int t;
			if (c == '+') t = (dp[i] > INF - x ? -1 : dp[i] + x);
			else t = (dp[i] > INF / x ? -1 : dp[i] * x);
			if (dp[j] == -1 or (t != -1 and t < dp[j])) dp[j] = t;
		}
	}
	if (dp[n] == -1) cout << "ouo";
	else cout << dp[n];
}
