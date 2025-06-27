#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> x(n), p(n);
	for (int i = 0;i < n;i++) {
		cin >> x[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> p[i];
	}
	vector<pair<int, int>> v(n);
	for (int i = 0;i < n;i++) {
		v[i] = {x[i], p[i]};
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++) {
		x[i] = v[i].first;
		p[i] = v[i].second;
	}
	vector<int> a(n);
	a[0] = p[0];
	for (int i = 1;i < n;i++) {
		a[i] = a[i - 1] + p[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int ld = lower_bound(x.begin(), x.end(), l) - x.begin();
		int rd = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;
		if (ld < n and rd >= 0 and ld < rd) {
			int sum = a[rd];
			if (ld > 0) {
				sum -= a[ld - 1];
			}
			cout << sum << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}
