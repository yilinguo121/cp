#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
signed main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n);
	for (int i = 0;i < n;i++) cin >> v[i];
	int l = *min_element(v.begin(), v.end());
	int r = *max_element(v.begin(), v.end());
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2, cnt = 0;
		for (auto x : v) {
			if (x < m) cnt += (m - x + a - 1) / a; //+a-1是為了確保是整數
			else cnt -= (x - m) / b;
		}
		if (cnt > 0) r = m - 1;
		else {
			l = m + 1;
			ans = m;
		}
	}
	cout << ans;
}

