#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> dp(1 << n, INF), a(m), v(m);
	for (int i = 0;i < m;i++) {
		int b;
		cin >> a[i] >> b;
		while (b--) {
			int x;
			cin >> x;
			v[i] |= (1 << (x - 1));
		}
	}
	dp[0] = 0;
	for (int i = 0;i < m;i++) {
		for (int j = (1 << n) - 1;j >= 0;j--) {
			if (dp[j] == INF) continue;
			dp[(j | v[i])] = min(dp[j] + a[i], dp[(j | v[i])]);
		}
	}
	cout << (dp[(1 << n) - 1] == INF ? -1 : dp[(1 << n) - 1]);
}
