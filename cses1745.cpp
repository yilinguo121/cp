#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	cin >> n;
	vector<bool> dp(100001);
	dp[0] = 1;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		for (int j = 100000;j >= 0;j--) {
			if (x > j) break;
			dp[j] = (dp[j] or dp[j - x]);
		}
	}
	vector<int> ans;
	for (int i = 1;i <= 100000;i++) if (dp[i]) ans.push_back(i);
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x << ' ';
}
