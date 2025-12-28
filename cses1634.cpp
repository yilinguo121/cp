#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = 2e9;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	vector<int> dp(k + 1, INF);
	dp[0] = 0;
	for (int i = 1;i <= k;i++) {
		for (auto x : v) {
			if (x > i) break;
			dp[i] = min(dp[i], dp[i - x] + 1);
		}
	}
	cout << (dp[k] == INF ? -1 : dp[k]);
}
