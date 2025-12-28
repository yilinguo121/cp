#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n), b(n);
	int ans = 0;
	for (auto &x : a) cin >> x;
	for (int i = 0;i < n;i++) {
		cin >> b[i];
		ans += min(a[i], b[i]);
	}
	while (q--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		x--;
		ans -= min(a[x], b[x]);
		if (c == 'A') a[x] = y;
		else b[x] = y;
		ans += min(a[x], b[x]);
		cout << ans << '\n';
	}
}
