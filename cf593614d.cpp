#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int l = 0, r = 2e9, ans;
		while (l <= r) {
			int m = (l + r) / 2;
			if ((m * (m + 1)) / 2 >= x) {
				r = m - 1;
				ans = m;
			}
			else {
				l = m + 1;
			}
		}
		cout << (ans * (ans + 1)) / 2 << '\n';
	}
}

