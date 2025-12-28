#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans = 0;
		for (int i = 0;i < min(n, m);i++) ans += v[i] * (m - i);
		cout << ans << '\n';
	}
}

