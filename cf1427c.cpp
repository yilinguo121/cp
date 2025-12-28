#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int r, n;
	cin >> r >> n;
	vector<int> dp(n + 1, -INF), x(n + 1), y(n + 1), t(n + 1);
	dp[0] = 0;
	x[0] = y[0] = 1;
	for (int i = 1;i <= n;i++) {
		cin >> t[i] >> x[i] >> y[i];
		for (int j = i - 1;j >= 0 and i - j <= 4 * r;j--) {
			if (t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j])) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}
