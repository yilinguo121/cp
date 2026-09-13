#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
const long long INF = numeric_limits<int>::max();
signed main() {
	IO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 0;i < n - 1;i++) {
			ans = max(ans, abs(v[n - 1] - v[i]) + abs(v[i] - v[i + 1]));
			ans = max(ans, abs(v[0] - v[i + 1]) + abs(v[i] - v[i + 1]));
		}
		cout << ans << '\n';
	}
}
