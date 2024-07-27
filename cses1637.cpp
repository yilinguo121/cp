#include<bits/stdc++.h>
using namespace std;
int dp[1000005] = {};
int f(int n) {
	if (n == 0) {
		return 0;
	}
	if (dp[n] != 0) {
		return dp[n];
	}
	dp[n] = 1e9;
	for (int i = n;i > 0;i /= 10) {
		dp[n] = min(dp[n], f(n - i % 10) + 1);
	}
	return dp[n];
}
int main() {
	int n;
	cin >> n;
	cout << f(n);
}
