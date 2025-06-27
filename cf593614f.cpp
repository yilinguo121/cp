#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long l = 0, r = 9000000000000000000;
	long long ans = -1;
	while (l <= r) {
		unsigned long long m = (1ull * l + r) / 2;
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


