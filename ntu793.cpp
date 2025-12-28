#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	IO
	int n;
	cin >> n;
	vector<int> v(n + 1), dp(n + 3);
	for (int i = 1;i <= n;i++) cin >> v[i];
	for (int i = n;i >= 1;i--) dp[i] = max(dp[i + 1] + v[i], dp[i + 2] + 2 * v[i]);
	cout << dp[1];
}
