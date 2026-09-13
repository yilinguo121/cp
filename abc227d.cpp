#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int l = 0, r = 1e18, ans = 0;
	while (l <= r) {
		int m = l - (l - r) / 2, cnt = 0;
		for (auto x : v) cnt += min(x, m);
		if (cnt / k >= m) l = m + 1, ans = m;
		else r = m - 1;
	}
	cout << ans;
}

