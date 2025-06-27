#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	int n, x, y;
	cin >> n;
	int l = 1, r = n;
	while (l <= r) {
		int t, m = (l + r) / 2;
		cout << "? " << l << ' ' << m << ' ' << 1 << ' ' << n << '\n';
		cout.flush();
		cin >> t;
		if (t < m - l + 1) {
			r = m - 1;
			x = m;
		}
		else l = m + 1;
	}
	l = 1, r = n;
	while (l <= r) {
		int t, m = (l + r) / 2;
		cout << "? " << 1 << ' ' << n << ' ' << l << ' ' << m << '\n';
		cout.flush();
		cin >> t;
		if (t < m - l + 1) {
			r = m - 1;
			y = m;
		}
		else l = m + 1;
	}
	cout << "! " << x << ' ' << y;
}

