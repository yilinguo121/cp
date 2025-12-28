#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n;
	string s, x;
	cin >> n >> s >> x;
	vector<int> w(n);
	w.back() = 1;
	for (int i = n - 2;i >= 0;i--) w[i] = (w[i + 1] * 10) % 7;
	vector<vector<bool>> dp(n + 1, vector<bool>(7));
	dp[n][0] = 1;
	for (int i = n - 1;i >= 0;i--) {
		int now = s[i] - '0';
		for (int j = 0;j < 7;j++) {
			if (x[i] == 'T') dp[i][j] = (dp[i + 1][j] or dp[i + 1][(j + now * w[i]) % 7]);
			else dp[i][j] = (dp[i + 1][j] and dp[i + 1][(j + now * w[i]) % 7]);
		}
	}
	cout << (dp[0][0] ? "Takahashi" : "Aoki");
}

