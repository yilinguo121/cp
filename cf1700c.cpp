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
		int d, ans = 0, now = v[0];
		for (int i = 1;i < n;i++) d = v[i] - v[i - 1], ans += abs(d), now += (d < 0 ? d : 0);
		cout << ans + abs(now) << '\n';
	}
}

