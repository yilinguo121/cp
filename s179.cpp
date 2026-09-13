#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1), pre(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
		pre[i] = v[i] + pre[i - 1];
	}
	while (q--) {
		int l, r, a, b, ans, L, R;
		cin >> l >> r >> a >> b;
		L = l, R = r;
		while (L <= R) {
			int m = (L + R) / 2;
			if ((pre[m] - pre[l - 1]) * (a + b) >= a * (pre[r] - pre[l - 1])) ans = m, R = m - 1;
			else L = m + 1;
		}
		cout << ans << '\n';
	}
}

