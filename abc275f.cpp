#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = 5000;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) cin >> v[i];
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF)), MIN(n + 1, vector<int>(m + 1, INF));
	dp[0][0] = MIN[0][0] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= m;j++) {
			if (j >= v[i] and dp[i - 1][j - v[i]] != INF) dp[i][j] = dp[i - 1][j - v[i]];
			dp[i][j] = min(dp[i][j], MIN[i - 1][j] + 1);
			MIN[i][j] = min(MIN[i - 1][j], dp[i][j]);
		}
	}
	for (int i = 1;i <= m;i++) cout << (dp[n][i] == INF ? -1 : dp[n][i]) << '\n';
}

