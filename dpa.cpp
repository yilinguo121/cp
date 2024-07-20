#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int inf = 1e9;
	cin >> n;
	vector<int> v(n), dp(n, inf);
	dp[0] = 0;
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		dp[i] = min(dp[i], dp[i - 1] + abs(v[i] - v[i - 1]));
		if (i > 1) {
			dp[i] = min(dp[i], dp[i - 2] + abs(v[i] - v[i - 2]));
		}
    }
	cout << dp[n - 1];
}
