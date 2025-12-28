#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> dp(h + 1, vector<int>(w + 1));
	dp[1][1] = 1;
	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			char c;
			cin >> c;
			if (c == '.') dp[i][j] = (1ll * dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
		}
	}
	cout << dp[h][w];
}
