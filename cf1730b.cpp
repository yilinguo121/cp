#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
vector<int> v, a;
int n;
double f(double m) {
	double mx = 0;
	for (int i = 0;i < n;i++) mx = max(mx, a[i] + abs(m - v[i]));
	return mx;
}
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		v.resize(n);
		a.resize(n);
		for (auto &x : v) cin >> x;
		for (auto &x : a) cin >> x;
		double l = 0, r = *max_element(v.begin(), v.end());
		for (int i = 0;i < 200;i++) {
			double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			if (f(m1) < f(m2)) r = m2;
			else l = m1;
		}
		cout << fixed << setprecision(15) << l << '\n';
	}
}
