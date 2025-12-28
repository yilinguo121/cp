#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long mod = 1000000007;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> dp(k + 1);
	dp[0] = 1;
	while (n--) {
		int x;
		cin >> x;
		for (int i = 1;i <= k;i++) dp[i] = (dp[i] + dp[i - 1]) % mod;
		for (int i = k;i >= 0;i--) if (i > x) dp[i] = ((dp[i] - dp[i - x - 1]) % mod + mod) % mod;
	}
	cout << dp[k];
}

