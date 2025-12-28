#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	//IO
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int ans = 0, now = INF;
		for (auto &x : v) {
			cin >> x;
		}
		for (int i = 0;i < n;i++) {
			if (v[i] >= now or (i < n - 1 and v[i] + v[i + 1] >= now)) {
				ans += now;
				break;
			}
			else {
				now = min(v[i], now);
				ans += now;
			}
		}
		cout << ans << '\n';
	}
}
