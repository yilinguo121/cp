#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
	IO
	int t;
	cin >> t;
	while (t--) {
		int l = 2, r = 999, ans, x;
		while (l < r) {
			int p = l + (r - l) / 3, q = r - (r - l) / 3;
			cout << "? " << p << ' ' << q << '\n';
			cout.flush();
			cin >> x;
			if (p * q == x) l = q + 1;
			else if (p * (q + 1) == x) {
				l = p + 1;
				r = q;
			}
			else r = p;
		}
		cout << "! " << l << '\n';
		cout.flush();
	}
}

