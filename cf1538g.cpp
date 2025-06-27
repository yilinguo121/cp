#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, y, a, b;
bool check(int m) {
	int i = x - min(a, b) * m;
	int j = y - min(a, b) * m;
	if (i < 0 or j < 0) return 0;
	if (a == b) return 1;
	return i / abs(a - b) + j / abs(a - b) >= m;
}
signed main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> x >> y >> a >> b;
		int l = 1, r = 1e9, ans = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m)) {
				l = m + 1;
				ans = m;
			}
			else r = m - 1;
		}
		cout << ans << '\n';
	}
}

