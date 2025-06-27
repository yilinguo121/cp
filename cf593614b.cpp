#include <bits/stdc++.h>
using namespace std;
int main() {
	int l = 0, r = 1000000000, ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		cout << "? " << m << '\n';
		cout.flush();
		int t;
		cin >> t;
		if (t) {
			r = m - 1;
		}
		else {
			l = m + 1;
			ans = m;
		}
	}
	cout << "! " << ans;
	cout.flush();
}


