#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(2 * n);
		for (auto &x : v) cin >> x;
		int a = 0, b = INF, c = INF , d = INF;
		for (auto x : v) a += abs(x);
		if (n == 1) {
			b = abs(v[0] - v[1]);
		}
		if (n == 2) {
			c = 0;
			for (auto x : v) c += abs(x - 2);
		}
		if (!(n % 2)) {
			d = 0;
			for (auto x : v) d += abs(x + 1);
			int mx = *max_element(v.begin(), v.end());
			d = d - abs(mx + 1) + abs(mx - n);
		}
		cout << min({a, b, c, d}) << '\n';
	}
}
