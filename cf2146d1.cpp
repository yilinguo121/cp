#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		vector<int> v(r + 1);
		int now = r;
		while (now >= 0) {
			int k = 1;
			while (k <= now) k *= 2;
			k--;
			for (int i = k - now;i <= now;i++) v[i] = (k ^ i);
			now = k - now - 1;
		}
		int ans = 0;
		for (int i = 0;i <= r;i++) ans += (i | v[i]);
		cout << ans << '\n';
		for (auto x : v) cout << x << ' ';
		cout << '\n';
	}
}
