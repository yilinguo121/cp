#include <bits/stdc++.h>
using namespace std;
long long x, y;
bool check(unsigned long long m) {
	long long cnt = 0;
	while (m >= x) {
		cnt += m / x;
		m = m % x + m / x;
	}
	return cnt >= y;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		if (x == 1) {
			cout << "1\n";
			continue;
		}
		unsigned long long l = 1, r = 9e18, ans = 0;
		while (l <= r) {
			unsigned long long m = (l + r) / 2;
			if (check(m)) {
				r = m - 1;
				ans = m;
			}
			else l = m + 1;
		}
		cout << ans << '\n';
	}
}

