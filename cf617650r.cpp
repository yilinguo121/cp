#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
const int mod = 998244353;
int main() {
	IO
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0;i < n;i++) dp[i][i] = 1;
	for (int l = n - 1;l >= 0;l--) {
		for (int r = l + 1;r < n;r++) {
			dp[l][r] = dp[l + 1][r] + dp[l][r - 1];
			if (s[l] == s[r]) dp[l][r]++;
			else dp[l][r] -= dp[l + 1][r - 1];
			dp[l][r] = ((dp[l][r] % mod) + mod) % mod;
		}
	}
	cout << dp[0][n - 1];
}
