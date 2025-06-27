#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
int k, x;
bool check(int m) {
	if (m <= k) return (m * (m + 1)) / 2 >= x;
	else return (k * (k - 1)) + k - ((2 * k - m) * (2 * k - 1 - m)) / 2 >= x;
}
signed main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		cin >> k >> x;
		int l = 1, r = 2 * k - 1, ans = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m)) {
				r = m - 1;
				ans = m;
			}
			else l = m + 1;
		}
		cout << (!ans ? 2 * k - 1 : ans) << '\n';
	}
}

