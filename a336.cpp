#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v(n + 1), dp(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
	}
	dp[0] = 0;
	for (int i = 1;i <= n;i++) {
		if (i > 1){
			dp[i] = max(dp[i - 1], v[i] + dp[i - 2]);
		}
		else {
			dp[i] = v[i];
		}
	}
	cout << dp[n] << '\n';
}
