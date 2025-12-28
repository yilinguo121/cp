#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long INF = numeric_limits<int>::max();
int main() {
	int n, d, ans1, ans2;
	cin >> n >> d;
	vector<int> v(n + 1);
	for (int i = 1; i <= n;i++) cin >> v[i];
	double l = 0, r = 100;
	for (int k = 0;k < 60;k++) {
		double m = (l + r) / 2, mx = -INF, mn = 0;
		int x = 1, y, bx = 1, by = d;
		vector<double> a(n + 1);
		for (int i = 1;i <= n;i++) a[i] = a[i - 1] + v[i] - m;
		for (int i = d;i <= n;i++) {
			if (a[i - d] < mn) mn = a[i - d], x = i - d + 1;
			if (a[i] - mn > mx) mx = a[i] - mn, y = i, bx = x, by = y;
		}
		if (mx >= -1e-9) l = m, ans1 = bx, ans2 = by;
		else r = m;
	}
	cout << ans1 << ' ' << ans2;
}

