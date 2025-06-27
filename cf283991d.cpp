#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) cin >> v[i];
	sort(v.begin() + 1, v.end());
	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		int l = 1, r = n, ans1 = 0, ans2 = n + 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (v[m] <= y) {
				l = m + 1;
				ans1 = m;
			}
			else {
				r = m - 1;
			}
		}
		l = 1, r = n;
		while (l <= r) {
			int m = (l + r) / 2;
			if (v[m] >= x) {
				r = m - 1;
				ans2 = m;
			}
			else {
				l = m + 1;
			}
		}
		cout << ans1 - ans2 + 1 << '\n';
	}
}

