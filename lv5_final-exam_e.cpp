#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO;
	int n, b;
	cin >> n >> b;
	vector<int> dp(n + 1);
	dp[1] = 2; // 1、2
	dp[2] = 4; // 11、12、21、22
	for (int i = 3;i <= n;i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 998244353;
	cout << dp[n];
}

