#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, m, y;
	cin >> n >> m >> y;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int ans = 0;
	for (int i = 0;i < (1 << n);i++) {
		if (__builtin_popcount(i) != m) continue;
		int now = -1;
		for (int j = 0;j < n;j++) {
			if (i >> j) {
				if (now == -1) now = v[j];
				now = gcd(now, v[j]);
			}
		}
		ans += (y / now);
	}
	cout << ans;
}
