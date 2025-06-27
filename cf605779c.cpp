#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
vector<double> w(100000), h(100000);
long long n, k;
bool f(double m) {
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		if (min(w[i], h[i]) >= m) cnt += ((int)(1.0 * max(w[i], h[i]) / m) * (int)(1.0 * min(w[i], h[i]) / m));
		if (cnt >= k) return 1;
	}
	return cnt >= k;
}
signed main() {
	IO
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> w[i] >> h[i];
	}
	double l = 1e-10, r = 1e12;
	for (int i = 1;i <= 60;i++) {
		double m = (l + r) / 2;
		if (f(m)) l = m;
		else r = m;
	}
	cout << fixed << setprecision(15) << l;
}

