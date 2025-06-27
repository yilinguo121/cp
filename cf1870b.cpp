#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int a = 0, b = 0;
		for (int i = 0;i < n;i++) {
			int t;
			cin >> t;
			a = (a ^ t);
		}
		for (int i = 0;i < m;i++) {
			int t;
			cin >> t;
			b = (b | t);
		}
		if (n % 2) {
			cout << a << ' ' << (a | b) << '\n';
		}
		else {
			b = ~b;
			cout << (a & b) << ' ' << a << '\n';
		}
	}
}

