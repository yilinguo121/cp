#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n), a(k);
		int ans = 0, pos = 0;
		for (auto &x : v) cin >> x, ans += x;
		for (auto &x : a) cin >> x;
		sort(a.begin(), a.end());
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (auto x : a) {
			pos += x - 1;
			if (pos < n) ans -= v[pos];
			else break;
			pos++;
		}
		cout << ans << '\n';
	}
}
