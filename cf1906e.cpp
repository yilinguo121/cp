#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, mx = 0;
	cin >> n;
	vector<int> v(2 * n);
	vector<vector<int>> a;
	for (auto &x : v) {
		cin >> x;
		if (x > mx) {
			a.push_back({x});
			mx = x;
		}
		else a.back().push_back(x);
	}
	int m = a.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1)), from(m + 1, vector<int>(n + 1));
	dp[0][0] = 1;
	for (int i = 0;i < m;i++) for (int j = 0, len = a[i].size();j <= n;j++) if (dp[i][j]) {
		dp[i + 1][j] = 1;
		if (j + len <= n) dp[i + 1][j + len] = from[i + 1][j + len] = 1;
	}
	if (!dp[m][n]) {
		cout << -1;
		return 0;
	}
	vector<bool> in(m);
	for (int i = m, now = n;i > 0;i--) if (from[i][now]) in[i - 1] = 1, now -= a[i - 1].size();
	for (int i = 0;i < m;i++) if (in[i]) for (auto x : a[i]) cout << x << ' ';
	cout << '\n';
	for (int i = 0;i < m;i++) if (!in[i]) for (auto x : a[i]) cout << x << ' ';
}

