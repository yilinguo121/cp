#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
int n;
vector<int> v;
int f(int x, int y) {
	vector<int> dp(n + 1);
	dp[x - 1] = 0;
	dp[x] = v[x];
	for (int i = x + 1;i <= y;i++) dp[i] = min(dp[i - 1], dp[i - 2]) + v[i];
	return min(dp[y], dp[y - 1]);
}
signed main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1;i <= n;i++) cin >> v[i];
	cout << (n == 2 ? min(v[1], v[2]) : min(v[1] + f(2, n), v[n] + v[2] + f(3, n - 1)));
}
