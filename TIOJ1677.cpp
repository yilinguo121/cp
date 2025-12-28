#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
vector<int> dp(101, -1);
int len(int n) {
	if (dp[n] != -1) return dp[n];
	if (n <= 2) return dp[n] = 1;
	return dp[n] = min(len(n - 1) + len(n - 2), 2000000000ll);
}
int get(int n, int k) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (k <= len(n - 2)) return get(n - 2, k);
	return get(n - 1, k - len(n - 2));
}
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k > len(n)) cout << "-1\n";
		else cout << get(n, k) << '\n';
	}
}
