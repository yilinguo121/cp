#include <bits/stdc++.h>
using namespace std;
int main() {
	int l = -1000000000, r = 1000000000, ans = 1000000001;
	while (l <= r) {
		int m = (l + r) / 2;
		cout << "? " << m << '\n';
		cout.flush();
		int t;
		cin >> t;
		if (!t) {
			l = m + 1;
		}
		else {
			r = m - 1;
			ans = m;
		}
	}
	cout << "! " << ans;
	cout.flush();
}


