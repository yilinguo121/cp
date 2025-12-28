#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n + 1);
		for (int i = 1;i <= n;i++) cin >> v[i];
		vector<vector<int>> pos(n + 1);
		vector<int> dp(n + 1);
		for (int i = 1;i <= n;i++) {
			pos[v[i]].push_back(i);
			dp[i] = max(dp[i - 1], (pos[v[i]].size() >= v[i] ? dp[pos[v[i]][pos[v[i]].size() - v[i]] - 1] + v[i] : 0));
		}
		cout << dp[n] << '\n';
	}
}
