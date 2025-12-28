#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int k, x;
		cin >> k >> x;
		int need = (1ll << k);
		vector<int> ans;
		while (x != need) {
			if (x < need) {
				ans.push_back(1);
				x *= 2;
			}
			else {
				ans.push_back(2);
				x = x - (2 * need - x);
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
}
