#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n), a(n);
	for (int i = 0;i < n;i++) cin >> v[i] >> a[i];
	double l = -2e9, r = 2e9;
	for (int i = 0;i < 60;i++) {
		double m = (l + r) / 2, max_l = -2e9, min_r = 2e9;
		for (int j = 0;j < n;j++) {
			max_l = max(max_l, v[j] - a[j] * m);
			min_r = min(min_r, v[j] + a[j] * m);
		}
		if (min_r >= max_l) r = m;
		else l = m;
	}
	cout << fixed << setprecision(15) << l << '\n';
}
