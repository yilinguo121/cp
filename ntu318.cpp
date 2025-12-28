#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long mod = 1000000007;
int main() {
	IO
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	int ans = 0;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		int now = 1;
		for (int j = max(1, x - 2);j <= min(n, x + 2);j++) now = (now + dp[j]) % mod;
		ans = (ans + now) % mod;
		dp[x] = (dp[x] + now) % mod;
	}
	cout << ans;
}
