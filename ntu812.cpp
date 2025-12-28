#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n, p, q;
	cin >> n >> p >> q;
	vector<int> a(p), b(q);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	vector<vector<int>> dp(p + 1, vector<int>(q + 1));
	for (int i = 0;i < p;i++) dp[i][q] = p - i;
	for (int i = 0;i < q;i++) dp[p][i] = q - i;
	for (int i = p - 1;i >= 0;i--) {
		for (int j = q - 1;j >= 0;j--) {
			if (a[i] == b[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
			else dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
		}
	}
	vector<int> ans;
	for (int i = 0, j = 0;i < p or j < q;) {
		if (i < p and j < q and a[i] == b[j]) {
			ans.push_back(a[i]);
			i++;
			j++;
		}
		else if (i == p or (i < p and j < q and dp[i + 1][j] > dp[i][j + 1])) {
			ans.push_back(b[j]);
			j++;
		}
		else {
			ans.push_back(a[i]);
			i++;
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x << ' ';
}
