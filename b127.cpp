#include <bits/stdc++.h>
using namespace std;
int main() {
	int dp[50] = {};
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2;i < 50;i++) dp[i] = dp[i - 1] + dp[i - 2];
	int n;
	while (cin >> n) cout << dp[n] << '\n';
}
