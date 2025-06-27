#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n), a(n);
		for (int i = 0;i < n;i++) cin >> v[i];
		for (int j = 0;j < n;j++) cin >> a[j];
		double l = *max_element(a.begin(), a.end()), r = 1e9;
		for (int i = 0;i < 60;i++) {
			double m = l + (r - l) / 2, max_l = 0, min_r = 1e9;
			for (int j = 0;j < n;j++) {
				max_l = max(max_l, v[j] - (m - a[j]));
				min_r = min(min_r, v[j] + (m - a[j]));
			}
			if (min_r >= max_l) r = m;
			else l = m;
		}
		double ans = 0;
		for (int i = 0;i < n;i++) ans = max(ans, v[i] - (l - a[i]));
		cout << fixed << setprecision(15) << ans << '\n';
	}
}

