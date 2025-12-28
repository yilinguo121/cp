#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int ans = INF;
	for (int i = 0;i < (1ll << n);i++) {
		int cnt = 0;
		int x = 0, y = 0;
		for (int j = 0;j < n;j++) {
			if (i & (1ll << j)) {
				cnt += a + b * max(0ll, v[j] - x) + c * max(0ll, x - v[j]) + d * abs(x - v[j]);
				x = v[j];
			}
			else {
				cnt += a + b * max(0ll, v[j] - y) + c * max(0ll, y - v[j]) + d * abs(y - v[j]);
				y = v[j];
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}

