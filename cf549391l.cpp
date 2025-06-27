#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	ull x = 0;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i;
			cin >> i;
			x |= 1ull << i;
		}
		if (type == 2) {
			int i;
			cin >> i;
			x &= ~(1ull << i);
		}
		if (type == 3) {
			int i;
			cin >> i;
			x ^= 1ull << i;
		}
		if (type == 4) {
			int i, j;
			cin >> i >> j;
			if ((x >> j) & 1) x |= 1ull << i;
			else x &= ~(1ull << i);
		}
		cout << x << '\n';
	}
}

