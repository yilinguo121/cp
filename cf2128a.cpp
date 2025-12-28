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
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		sort(v.begin(), v.end());
		int ans = 0;
		while (!v.empty()) {
			auto it = upper_bound(v.begin(), v.end(), k);
			if (it == v.begin()) {
				ans += v.size();
				break;
			}
			if (it == v.end()) {
				v.pop_back();
			}
			else {
				v.erase(--it);
			}
			for (auto &x : v) x *= 2;
		}
		cout << ans << '\n';
	}
}
