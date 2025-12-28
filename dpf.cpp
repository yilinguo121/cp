#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	string x, y;
	cin >> x >> y;
	vector<vector<int>> dp(x.size() + 1, vector<int>(y.size() + 1)), pa(x.size() + 1, vector<int>(y.size() + 1));
	for (int i = 1;i <= x.size();i++) {
		for (int j = 1;j <= y.size();j++) {
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				pa[i][j] = 1;
			}
			else if (dp[i - 1][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
				pa[i][j] = 2;
			}
			else {
				dp[i][j] = dp[i][j - 1];
				pa[i][j] = 3;
			}
		}
	}
	string ans;
	int i = x.size(), j = y.size();
	while (i > 0 and j > 0) {
		if (pa[i][j] == 1) {
			ans += x[i - 1];
			i--;
			j--;
		}
		else if (pa[i][j] == 2) i--;
		else j--;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}
