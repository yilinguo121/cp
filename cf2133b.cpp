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
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans = 0;
		for (int i = 0;i < n;i++) if (!(i % 2)) ans += v[i];
		cout << ans << '\n';
	}
}

